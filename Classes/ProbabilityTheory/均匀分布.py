import numpy as np
import matplotlib.pyplot as plt

# 参数设置
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False
n_samples = 10000
bins = 20

# 使用均匀分布生成样本, 落在 [0, 1]
uniform_samples = np.random.rand(n_samples)

# 绘制样本分布直方图
plt.hist(uniform_samples, bins=bins, alpha=0.5, edgecolor='black')

# 样本均值
mean = np.array(uniform_samples).mean()
# 均值线
plt.axvline(mean, color='r')
plt.annotate('mean={}'.format(mean), xy=(mean, 0), xytext=(mean, n_samples/2/bins))

plt.xlabel('值')
plt.ylabel('频数')
plt.title('均匀分布样本直方图')
plt.show()
