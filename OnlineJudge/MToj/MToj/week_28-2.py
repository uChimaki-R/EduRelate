def fact(f):
    ans = 1
    for i in range(2, f + 1):
        ans *= i
    return ans


m, n = [int(i) for i in input().strip().split(' ')]
ret = str(int(fact(m+n)//(fact(m)*fact(n))))[-100:]
ret = ret.rjust(100, '0')
# print(ret)
for t in range(10):
    print(ret[t*10:t*10+10])
