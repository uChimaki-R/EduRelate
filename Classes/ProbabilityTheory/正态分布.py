import numpy as np
import scipy.stats as stats
import matplotlib.pyplot as plt
import time

# 参数设置
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False
mu = 0  # 均值
sigma = 1  # 标准差
n_samples = 100000  # 样本数量


def get_samples_from_norm():
    start = time.time()
    # 创建正态分布对象
    normal_distribution = stats.norm(loc=mu, scale=sigma)

    # 生成正态分布样本
    samples = normal_distribution.rvs(size=n_samples)

    end = time.time()
    print(f"get_samples_from_norm cost {end-start} s")
    return samples


def get_samples_from_rand():
    start = time.time()
    # 使用均匀分布生成随机数, 落在 [0, 1]
    uniform_samples = np.random.rand(n_samples)

    # 使用标准正态分布分布律转换随机数
    normal_samples = stats.norm.ppf(uniform_samples, loc=mu, scale=sigma)

    end = time.time()
    print(f"get_samples_from_rand cost {end - start} s")
    return normal_samples


samples1 = get_samples_from_norm()
samples2 = get_samples_from_rand()
# 绘制直方图
plt.hist(samples1, bins=80, alpha=0.5, edgecolor='black')

# plt.plot(
#     np.linspace(-4, 4, n_samples),
#     stats.norm.pdf(np.linspace(-4, 4, n_samples),
#                    loc=np.array(samples1).mean(),
#                    scale=np.array(samples1).std()
#                    ),
#     color='r'
# )

plt.xlabel('值')
plt.ylabel('频数')
plt.title('正态分布样本直方图')
plt.show()
