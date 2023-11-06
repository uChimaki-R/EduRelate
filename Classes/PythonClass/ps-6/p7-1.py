dic = dict()
for obj in input().strip().split(' '):
    if dic.get(obj, None):
        dic[obj] += 1
    else:
        dic[obj] = 1
lis = sorted([(key, val) for key, val in dic.items()], key=lambda x: -x[1])
for name, cnt in lis:
    print(f'{name}:{cnt}')
