import random

seed = int(input().strip())
random.seed(seed)
ans = random.randrange(1, 101)

for i in range(6):
    sts = input().strip()
    if sts == '':
        break
    guess = int(sts)
    if guess == ans:
        print('你赢了')
        exit(0)
    elif guess > ans:
        print('大了')
    else:
        print('小了')
else:
    print('你输了')
