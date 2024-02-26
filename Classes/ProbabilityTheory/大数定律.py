import numpy as np
import scipy.stats as stats
import matplotlib.pyplot as plt


edge = 12000  # n的大小最大值
seed = 100  # 随机种子固定住, 保证曲线比较连续

mean_uniform = []
mean_2point = []
mean_normal = []

for n in range(1, edge):
    # 计算并记录各个分布在当前n下的样本平均值

    # 固定种子
    np.random.seed(seed)

    # 均匀分布
    uniform_samples = np.random.rand(n)
    mean_uniform.append(uniform_samples.mean())

    # 两点分布
    mean_2point.append(np.random.choice([0, 1], size=n).mean())

    # 正态分布
    mean_normal.append(stats.norm.ppf(uniform_samples, loc=0.5, scale=1).mean())

plt.plot(range(1, edge), mean_uniform, label='mean_uniform')
plt.plot(range(1, edge), mean_2point, label='mean_2point')
plt.plot(range(1, edge), mean_normal, label='mean_normal')

plt.axhline(0.5, color='black', linestyle='--')

plt.legend()
plt.show()
