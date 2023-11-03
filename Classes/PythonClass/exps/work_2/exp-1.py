import random

dic = {}
for i in range(1, 41):
    code = '2023' + str(i).rjust(2, '0')
    score = {
        '语文': random.randint(50, 151),
        '数学': random.randint(50, 151),
        '英语': random.randint(50, 151)
    }
    score['总分'] = sum(score.values())
    dic[code] = score
# print(dic)
lis = [(key, value['总分']) for key, value in dic.items()]
lis_sorted = sorted(lis, key=lambda x: -x[1])
for code, total in lis_sorted:
    print('id:', code, '\ttotal:', total)
