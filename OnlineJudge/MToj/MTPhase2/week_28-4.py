def fact(f):
    ans = 1
    for i in range(2, f + 1):
        ans *= i
    return ans


n = int(input().strip()) // 2
print('{:.4f}'.format(1 - fact(2 * n - 2) // (fact(n - 1) ** 2) / (4 ** (n - 1))))
