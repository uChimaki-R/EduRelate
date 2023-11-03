def is_sxh(num, n):
    lis = []
    for i in map(int, str(num)):
        lis.append(i**n)
    return num == sum(lis)


for i in range(100, 100000):
    if is_sxh(i, len(str(i))):
        print(i)
