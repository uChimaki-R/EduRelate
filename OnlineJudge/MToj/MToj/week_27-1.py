ticket = int(input().strip())
ps = [0]
for i in range(1, 90):
    ps.append(ps[i-1]+(1-ps[i-1])*0.006)
ps.append(1)
print('{:.6f}%'.format(ps[ticket]*100))
