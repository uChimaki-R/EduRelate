import networkx as nx
import matplotlib.pyplot as plt
import csv


plt.rcParams["font.sans-serif"] = [u"SimHei"]
plt.rcParams["axes.unicode_minus"] = False
plt.figure(figsize=(32, 18))

G = nx.DiGraph()

with open('triples.csv', 'r', encoding='utf-8') as f:
    reader = csv.reader(f)
    datas = [line for line in reader]
    del datas[0]

# # 取一部分方便查看
# datas = datas[:25]

nodes = list({data[0] for data in datas}.union({data[1] for data in datas}))
# print(nodes)

G.add_nodes_from(nodes)
for data in datas:
    G.add_edge(data[0], data[1], relation=data[3])

pos = nx.spring_layout(G, k=0.4)
nx.draw(G, pos, with_labels=True, node_size=150, font_size=10)

# 在边上添加关系标签
edge_labels = nx.get_edge_attributes(G, 'relation')
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_size=10)

plt.savefig('outputs/exp-2-3_output.png')
plt.show()
