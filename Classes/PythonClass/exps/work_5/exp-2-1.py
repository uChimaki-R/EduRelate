import matplotlib.pyplot as plt
import numpy as np


with open('wn18.txt', 'r') as f:
    datas = f.readlines()

groups = [datas[i:i + 52] for i in range(0, len(datas), 52)]
# print(groups)

datas_dict = {}
for group in groups:
    name = group[0].strip()
    del group[0]

    group = [data.split() for data in group]
    mrr = [float(data[0]) for data in group]
    hit = [float(data[1]) for data in group]
    # print(mrr, hit)

    datas_dict[name] = {
        'mrr': mrr,
        'hit': hit
    }

# print(datas_dict)

plt.subplot(1, 2, 1)
plt.title('WN18 Validation MRR')
plt.xlabel('Epochs')
plt.ylabel('MRR')

for key, val in datas_dict.items():
    plt.plot(np.linspace(0, 5000, 51), datas_dict[key]['mrr'], label=key)
plt.legend()

plt.subplot(1, 2, 2)
plt.title('WN18 Validation HITs@10')
plt.xlabel('Epochs')
plt.ylabel('Hits@10')

for key, val in datas_dict.items():
    plt.plot(np.linspace(0, 5000, 51), datas_dict[key]['hit'], label=key)
plt.legend()

plt.show()
