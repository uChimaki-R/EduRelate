n = int(input().strip())
lis = [int(i) for i in input().strip().split(' ')]
lis = sorted(lis)
lis.pop(0)
lis.pop(0)
lis.pop(-1)
lis.pop(-1)
tt = 0.0
for i in lis:
    tt += i
print('aver={:.2f}'.format(tt/len(lis)))
