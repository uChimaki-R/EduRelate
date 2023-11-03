def get_add(lis: list, w: int):
    global ans
    ans += w*len(lis)
    for i in lis:
        if isinstance(i, list):
            ans -= w
            get_add(i, w+1)


ls_str = input()
ls = eval(ls_str)
weight = 1
ans = 0
get_add(ls, weight)
print(ans)
