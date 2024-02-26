import pandas as pd
from collections import Counter
import jieba
from sklearn.model_selection import train_test_split
import torch
import torch.nn as nn
import torch.optim as optim
from torch.utils.data import DataLoader, Dataset
from tqdm import tqdm
import time
import json


# 读取数据
def read_data(file_path):
    with open(file_path, 'r', encoding='utf-8') as f:
        lines = f.readlines()
    return [line.strip().split('\t') for line in lines]


# 分词
def tokenize(text):
    return list(jieba.cut(text))


# 将标题转换为数字序列
def convert_to_numerical(title, vocab, max_len=10):
    res = [vocab.get(word, vocab['<UNK>']) for word in title][:max_len]
    if len(title) >= max_len:
        return res
    else:
        return res + [vocab['<PAD>']] * (max_len - len(title))


class NewsDataset(Dataset):
    def __init__(self, titles, labels):
        self.titles = titles
        self.labels = labels

    def __len__(self):
        return len(self.titles)

    def __getitem__(self, idx):
        return self.titles[idx], self.labels[idx]


# 构建模型
class NewsClassifier(nn.Module):
    def __init__(self, vocab_size, embedding_dim, hidden_dim, output_dim):
        super(NewsClassifier, self).__init__()
        self.embedding = nn.Embedding(vocab_size, embedding_dim)
        self.lstm = nn.LSTM(embedding_dim, hidden_dim, batch_first=True)
        self.fc = nn.Linear(hidden_dim, output_dim)

    def forward(self, x):
        x = self.embedding(x)
        x, _ = self.lstm(x)
        x = self.fc(x[:, -1, :])
        return x


def save():
    train_data = read_data('dataset/Train.txt')
    test_data = read_data('dataset/Test.txt')

    with open("train_title_tokenize.txt", 'wb') as f:
        tq1 = tqdm(total=len(train_data))
        for line in train_data:
            f.write((str(tokenize(line[-1])) + '\n').encode())
            tq1.update()
        tq1.close()
    with open("test_title_tokenize.txt", 'wb') as f:
        tq2 = tqdm(total=len(test_data))
        for line in test_data:
            f.write((str(tokenize(line[-1])) + '\n').encode())
            tq2.update()
        tq2.close()


def read():
    train_titles = []
    test_titles = []
    with open("train_title_tokenize.txt", 'rb') as f:
        for line in f.readlines():
            train_titles.append(eval(line.decode()))
    with open("test_title_tokenize.txt", 'rb') as f:
        for line in f.readlines():
            test_titles.append(eval(line.decode()))
    return train_titles, test_titles


def save_2(train_titles, test_titles):
    with open("train_title_num.txt", 'w') as f:
        tq1 = tqdm(total=len(train_titles))
        for line in train_titles:
            f.write(str(line) + '\n')
            tq1.update()
        tq1.close()
    with open("test_title_num.txt", 'w') as f:
        tq2 = tqdm(total=len(test_titles))
        for line in test_titles:
            f.write(str(line) + '\n')
            tq2.update()
        tq2.close()


def read_2():
    train_titles = []
    test_titles = []
    with open("train_title_num.txt", 'r') as f:
        for line in f.readlines():
            train_titles.append(eval(line))
    with open("test_title_num.txt", 'r') as f:
        for line in f.readlines():
            test_titles.append(eval(line))
    return train_titles, test_titles


def get_result():
    train_data = read_data('dataset/Train.txt')
    train_titles, test_titles = read_2()
    test_titles = torch.tensor(test_titles)

    vocab = json.load(open('vocab.json', 'r', encoding='utf-8'))

    embedding_dim = 128
    hidden_dim = 256
    output_dim = len(set([line[0] for line in train_data]))
    batch_size = 96

    device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')

    test_dataset = NewsDataset(test_titles, torch.tensor([0] * len(test_titles)))
    test_loader = DataLoader(test_dataset, batch_size=batch_size, shuffle=False)

    tag2name = json.load(open('tag2name.json', 'r', encoding='gbk'))

    state_dict = torch.load("nn_1.pth")
    model = NewsClassifier(len(vocab), embedding_dim, hidden_dim, output_dim).to(device)
    model.load_state_dict(state_dict)
    model.eval()
    with torch.no_grad():
        with open('result2.txt', 'w') as f:
            tq = tqdm(total=len(test_loader))
            for title in test_loader:
                to_pre = title[0].to(device)
                output = model(to_pre)
                _, predicted = torch.max(output, 1)
                for pre in predicted:
                    f.write(tag2name[str(pre.item())] + '\n')
                tq.update()
            tq.close()


def train_save():
    # 读取和转换为数字序列耗时太长, debug不方便, 先存再读

    # save()
    # train_titles, test_titles = read()
    #
    # # 构建词汇表
    # word_counter = Counter()
    # for title in train_titles + test_titles:
    #     word_counter.update(title)
    #
    # vocab = {word: i for i, (word, _) in enumerate(word_counter.most_common())}
    # vocab['<PAD>'] = len(vocab)
    # vocab['<UNK>'] = len(vocab)
    #
    # with open("vocab.json", "w", encoding="utf-8") as f:
    #     json.dump(vocab, f, ensure_ascii=False, indent=4)
    #
    # train_titles = [convert_to_numerical(title, vocab) for title in train_titles]
    # test_titles = [convert_to_numerical(title, vocab) for title in test_titles]
    #
    # save_2(train_titles, test_titles)

    start = time.time()
    tqdm.write("Getting train_titles and test_titles")
    train_data = read_data('dataset/Train.txt')

    # # 保存标签对应类型名字
    # tag2name = {}
    # for lis in train_data:
    #     tag2name[lis[0]] = lis[1]
    # with open("tag2name.json", "w", encoding="utf-8") as f:
    #     json.dump(tag2name, f, ensure_ascii=False, indent=4)

    train_titles, test_titles = read_2()
    train_titles = torch.tensor(train_titles)
    test_titles = torch.tensor(test_titles)
    vocab = json.load(open('vocab.json', 'r', encoding='utf-8'))
    end = time.time()
    tqdm.write(f'cost: {round(end - start, 3)}s')

    # 划分训练集和测试集
    tqdm.write("Divide the training set and the test set")
    X_train, X_test, y_train, y_test = train_test_split(train_titles, [int(line[0]) for line in train_data],
                                                        test_size=0.2, random_state=42)

    # 参数设置
    tqdm.write("Setting parameters")
    embedding_dim = 128
    hidden_dim = 256
    output_dim = len(set([line[0] for line in train_data]))
    learning_rate = 0.01
    epochs = 10
    batch_size = 96

    # 训练模型
    max_acc = 0.0
    model_dict = {}

    tqdm.write("Start training")
    device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
    model = NewsClassifier(len(vocab), embedding_dim, hidden_dim, output_dim).to(device)
    criterion = nn.CrossEntropyLoss()
    optimizer = optim.Adam(model.parameters(), lr=learning_rate)

    train_dataset = NewsDataset(X_train, y_train)
    test_dataset = NewsDataset(X_test, y_test)

    train_loader = DataLoader(train_dataset, batch_size=batch_size, shuffle=True)
    test_loader = DataLoader(test_dataset, batch_size=batch_size, shuffle=False)

    for epoch in range(epochs):
        model.train()
        tqdm.write("Train")
        start = time.time()
        dl = tqdm(total=len(train_loader))
        tqdm.write('Epoch {}/{}'.format(epoch + 1, epochs))
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

        # 测试
        tqdm.write("Test")
        model.eval()
        correct = 0
        total = 0
        with torch.no_grad():
            dl = tqdm(total=len(test_loader))
            for data in test_loader:
                inputs, labels = data[0].to(device), data[1].to(device)
                outputs = model(inputs)
                _, predicted = torch.max(outputs.data, 1)
                total += labels.size(0)
                correct += (predicted == labels).sum().item()
                dl.update()
            dl.close()
        acc = round(100 * correct / total, 2)
        tqdm.write(f'Accuracy: {acc}%')
        if acc > max_acc:
            max_acc = acc
            model_dict = model.state_dict()
        tqdm.write('-' * 20)

    filename = "nn_1.pth"
    # 保存模型
    print(f'max_acc: {max_acc}%')
    torch.save(model_dict, filename)


if __name__ == '__main__':
    # train_save()

    # 预测测试集
    get_result()
