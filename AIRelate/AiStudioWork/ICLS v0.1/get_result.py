import torch
import torchvision
from torchvision import transforms
from torch.utils.data import DataLoader, Dataset
from PIL import Image
import os
import numpy as np
from tqdm import tqdm


# 加载数据集
class CustomDataset(Dataset):
    def __init__(self, txt_path, image_dir, transform=None):
        self.txt_path = txt_path
        self.image_dir = image_dir
        self.transform = transform
        with open(txt_path, 'r') as f:
            self.lines = f.readlines()

    def __len__(self):
        return len(self.lines)

    def __getitem__(self, index):
        image_name = self.lines[index].strip()
        image_path = os.path.join(self.image_dir, image_name)
        image = Image.open(image_path).convert('RGB')
        if self.transform:
            image = self.transform(image)
        return image, image_name


pre_dataset = CustomDataset(
    txt_path='dataset/test.txt',
    image_dir='dataset/images',
    transform=transforms.Compose(
        [
            transforms.Resize([128, 128]),
            transforms.ToTensor(),
            transforms.Normalize([0.485, 0.456, 0.406], [0.229, 0.224, 0.225])
        ]
    )
)


model = torchvision.models.resnet152(weights=torchvision.models.ResNet152_Weights.IMAGENET1K_V1)
num_ftrs = model.fc.in_features
model.fc = torch.nn.Linear(num_ftrs, 102)

filename = 'resnet152_all_sgd_961.pth'
state_dict = torch.load(filename)
model.load_state_dict(state_dict)

dataloader = DataLoader(pre_dataset, batch_size=112, shuffle=False)
model.eval()

dl = tqdm(total=len(dataloader))

with open("result.txt", 'w') as f:
    for i, data in enumerate(dataloader, 0):
        output = model(data[0])
        # 得到概率最大的那个
        _, preds_tensor = torch.max(output, 1)

        preds = np.squeeze(preds_tensor.numpy())
        for name, tag in zip(data[1], preds):
            f.write(f'{name}\t{tag}\n')
        dl.update()
