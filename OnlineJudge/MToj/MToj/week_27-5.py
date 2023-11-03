def ft(nn):
    ret = 1
    for i in range(1, nn + 1):
        ret *= i
    return ret


n, k, w = [int(i) for i in input().strip().split(' ')]
t = 3 * w
if t > k:
    print(0)
else:
    print(int(ft(k) / ft(k - t)))
