import torch
import torchvision
from torchvision import transforms
from torch.utils.data import DataLoader, Dataset
from PIL import Image
import os
import time
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
        line = self.lines[index].strip().split()
        image_name = line[0]
        image_label = int(line[1])
        image_path = os.path.join(self.image_dir, image_name)
        image = Image.open(image_path).convert('RGB')
        if self.transform:
            image = self.transform(image)
        return image, image_label


train_dataset = CustomDataset(
    txt_path='dataset/train.txt',
    image_dir='dataset/images',
    transform=transforms.Compose(
        [
            transforms.Resize([128, 128]),
            transforms.RandomRotation(45),  # 随机旋转，-45到45度之间随机选
            transforms.CenterCrop(94),  # 从中心开始裁剪
            transforms.RandomHorizontalFlip(p=0.5),  # 随机水平翻转 选择一个概率概率
            transforms.RandomVerticalFlip(p=0.5),  # 随机垂直翻转
            transforms.ColorJitter(brightness=0.2, contrast=0.1, saturation=0.1, hue=0.1),
            # 参数1为亮度，参数2为对比度，参数3为饱和度，参数4为色相
            transforms.RandomGrayscale(p=0.025),  # 概率转换成灰度率，3通道就是R=G=B
            transforms.ToTensor(),
            transforms.Normalize([0.485, 0.456, 0.406], [0.229, 0.224, 0.225])  # 均值，标准差
        ]
    )
)

test_dataset = CustomDataset(
    txt_path='dataset/train.txt',
    image_dir='dataset/images',
    transform=transforms.Compose(
        [
            transforms.Resize([128, 128]),
            transforms.ToTensor(),
            transforms.Normalize([0.485, 0.456, 0.406], [0.229, 0.224, 0.225])
        ]
    )
)


def train_save(model, train_loader, test_loader, criterion, optimizer, num_epochs, filename):
    # 训练模型
    device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")
    model.to(device)

    model.train()
    for epoch in range(num_epochs):
        start = time.time()
        dl = tqdm(total=len(train_loader))
        tqdm.write('Epoch {}/{}'.format(epoch + 1, num_epochs))
        running_loss = 0.0
        for i, data in enumerate(train_loader, 0):
            inputs, labels = data[0].to(device), data[1].to(device)
            optimizer.zero_grad()
            outputs = model(inputs)
            loss = criterion(outputs, labels)
            loss.backward()
            optimizer.step()
            running_loss += loss.item()
            dl.update()
        dl.close()
        end = time.time()
        tqdm.write(f'Loss: {running_loss / (i + 1)} cost: {round(end - start, 3)}s')
        tqdm.write('-' * 20)

    # 测试模型
    tqdm.write("Valid part")
    model.eval()
    correct = 0
    total = 0
    with torch.no_grad():
        for data in test_loader:
            images, labels = data[0].to(device), data[1].to(device)
            outputs = model(images)
            _, predicted = torch.max(outputs.data, 1)
            total += labels.size(0)
            correct += (predicted == labels).sum().item()

    tqdm.write(f'Accuracy: {100 * correct / total}%')
    tqdm.write('-' * 20)
    # 保存模型
    torch.save(model.state_dict(), filename)


if __name__ == '__main__':
    # 定义ResNet模型
    model = torchvision.models.resnet152(weights=torchvision.models.ResNet152_Weights.IMAGENET1K_V1)
    num_ftrs = model.fc.in_features
    model.fc = torch.nn.Linear(num_ftrs, 102)

    train_loader = DataLoader(train_dataset, batch_size=224, shuffle=True)
    test_loader = DataLoader(test_dataset, batch_size=224, shuffle=False)

    # # 定义损失函数和优化器
    criterion = torch.nn.CrossEntropyLoss()
    # optimizer = torch.optim.SGD(model.parameters(), lr=0.01)
    #
    # train_save(model, train_loader, test_loader, criterion, optimizer, 30, 'resnet152_ol_fc.pth')

    # 训练所有参数
    for param in model.parameters():
        param.requires_grad = True

    filename = 'resnet152_all_sgd_961.pth'

    optimizer = torch.optim.SGD(model.parameters(), lr=0.001)

    state_dict = torch.load(filename)
    model.load_state_dict(state_dict)

    train_save(model, train_loader, test_loader, criterion, optimizer, 10, 'resnet152_all_sgd.pth')
