val = input().strip()
t1, t2 = input().strip().split(' ')
pos = len(val) - 1
for c in val[::-1]:
    if c == t1:
        print(pos, t1)
    if c == t2:
        print(pos, t2)
    pos -= 1
