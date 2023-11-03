upper = tuple(chr(i) for i in range(ord('A'), ord('Z') + 1))
lower = tuple(chr(i) for i in range(ord('Z'), ord('A') - 1, -1))
dic = {}
for up, lo in zip(upper, lower):
    dic[up] = lo
sts = input()
ans = ''
for c in sts:
    if c in upper:
        ans += dic[c]
    else:
        ans += c
print(ans)
