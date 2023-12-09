import numpy as np
import matplotlib.pyplot as plt
from collections import Counter


# 设置参数
plt.rcParams['font.sans-serif'] = ['SimHei']
n = 100
p = 0.5
cnt = 10000

# 生成数据
list_k = []
for _ in range(cnt):
    # 从0、1中选择, 得出选择1的次数
    list_k.append(np.random.choice([0, 1], size=n).sum())
val_k = Counter(list_k)
print(val_k)

# 绘制直方图
plt.bar(list(val_k.keys()), [val/cnt for val in val_k.values()])
# 添加标题和标签
plt.title('二项分布图')
plt.xlabel('1的次数')
plt.ylabel('频次/总次数')
# 显示图形
plt.show()
