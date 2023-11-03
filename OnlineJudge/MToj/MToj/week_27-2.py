times = int(input().strip())
p = 0.0
for i in range(1, times+1):
    p += (1/i)*0.5**i
print('{:.6f}'.format(p))
