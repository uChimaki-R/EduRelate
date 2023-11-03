cnt = 0
for big in range(100, 0, -1):
    for mid in range(1, 101 - big):
        total = 100 - big * 3 - mid * 2
        small = 100 - big - mid
        if total * 2 == small:
            print(big, mid, small)
            cnt += 1

print(f'共有{cnt}种组合')
