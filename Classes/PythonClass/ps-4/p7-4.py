dic1: dict = eval(input().strip())
dic2: dict = eval(input().strip())
for obj, cnt in dic2.items():
    if dic1.get(obj, None):
        dic1[obj] += cnt
    else:
        dic1[obj] = cnt
lis = sorted([(obj, cnt) for obj, cnt in dic1.items()], key=lambda x: -x[1])
for obj, cnt in lis:
    print(f'{obj}销量{cnt}')
