a, b = [int(i) for i in input().strip().split()]
tot = 0
lis3 = []
lis5 = []
lis7 = []
for i in range(a, b + 1):
    if i % 3 == 0:
        lis3.append(i)
    if i % 5 == 0:
        lis5.append(i)
    if i % 7 == 0:
        lis7.append(i)
print(len(set(lis3).intersection(set(lis5)).intersection(set(lis7))))
