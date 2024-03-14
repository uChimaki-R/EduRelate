n, m = [int(i) for i in input().strip().split(' ')]
t1 = n - (m - 1)
t2 = n // m
t3 = n % m
print(t2 * (t2 - 1) // 2 * (m - t3) + t2 * (t2 + 1) // 2 * t3, t1 * (t1 - 1) // 2)
