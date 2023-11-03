ages = 0
cnt = 0.0
man = 0
while True:
    info = input().strip()
    if info == '':
        break
    name, gender, age = info.split(' ')
    if gender == '男':
        man += 1
    ages += float(age)
    cnt += 1.0
print('平均年龄是{:.2f} 男性人数是{}'.format(ages/cnt, man))
