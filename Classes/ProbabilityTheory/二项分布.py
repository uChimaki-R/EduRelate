import numpy as np
import matplotlib.pyplot as plt
import scipy.stats as stats
from collections import Counter


# 设置参数
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False
n = 100
p = 0.5
cnt = 100000  # 实验次数

# 生成数据
list_k = []
for _ in range(cnt):
    # 从0、1中选择, 得出选择1的次数
    list_k.append(np.random.choice([0, 1], size=n).sum())
val_k = Counter(list_k)

# 根据每次实验中出现1的次数的各自的频数(0: 0次频数, 1: 1次频数, ..., n: n次频数) 绘制直方图
plt.bar(list(val_k.keys()), [val/cnt for val in val_k.values()])

# 根据具体数据(list_k)(每次实验的1的个数)(0, 0, 1, 1, 5, 5, ...)(共cnt个数据) 绘制正态分布曲线
plt.plot(
    np.linspace(0, n, cnt),
    stats.norm.pdf(np.linspace(0, n, cnt),
                   loc=np.array(list_k).mean(),
                   scale=np.array(list_k).std()
                   ),
    color='r'
)

plt.title('二项分布图')
plt.xlabel('1的次数')
plt.ylabel('频次/总次数')
plt.show()
