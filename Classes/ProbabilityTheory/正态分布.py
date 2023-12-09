import numpy as np
import scipy.stats as stats
import matplotlib.pyplot as plt

# 参数设置
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False
mu = 0  # 均值
sigma = 1  # 标准差
n_samples = 10000  # 样本数量

# 使用均匀分布生成随机数, 落在 [-1, 1]
uniform_samples = np.random.rand(n_samples) * 2 - 1
print(uniform_samples)

# 使用标准正态分布分布律转换随机数
normal_samples = stats.norm.ppf((uniform_samples + 1) / 2, loc=mu, scale=sigma)
print(normal_samples)

# 绘制直方图
plt.hist(normal_samples, bins=30, alpha=0.5, label='标准正态分布', edgecolor='black')
# plt.hist(uniform_samples, bins=30, alpha=0.5, label='均匀分布')
# plt.legend()
plt.xlabel('值')
plt.ylabel('频数')
plt.title('正态分布样本直方图')
plt.show()
