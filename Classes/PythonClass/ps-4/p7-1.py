cnt = int(input().strip())
for _ in range(cnt):
    t = int(input().strip())
    one_list = []
    for __ in range(t):
        name, s1, s2 = input().strip().split(' ')
        one_list.append((name, s1, s2))
    one_list = sorted(one_list, key=lambda x: (-int(x[1]), -int(x[2]), x[0]))
    # print(one_list)
    p = 1
    i = 0
    while i < len(one_list):
        if i > 0 and one_list[i][1] == one_list[i - 1][1] and one_list[i][2] == one_list[i - 1][2]:
            temp = p - 1
            while i < len(one_list) and one_list[i][1] == one_list[i - 1][1] and one_list[i][2] == one_list[i - 1][2]:
                print(temp, *one_list[i])
                i += 1
                p += 1
        else:
            print(p, *one_list[i])
            p += 1
            i += 1
