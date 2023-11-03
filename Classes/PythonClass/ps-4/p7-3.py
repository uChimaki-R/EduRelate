award = {"张富": 50000, "赵诺": 45000}
for _ in range(5):
    name = input().strip()
    if name in award.keys():
        print(f'{name}的年终奖为{award[name]}')
    else:
        print(f'{name}的年终奖为30000')
