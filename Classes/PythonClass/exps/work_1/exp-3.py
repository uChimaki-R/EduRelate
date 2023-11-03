import random


if __name__ == '__main__':
    role = {"player": [5, 2, 3, 4], "monster": [10, 1, 2]}
    print('战斗开始, 双方的信息如下')
    print(f'player: 血量:{role["player"][0]}, 各技能伤害:{role["player"][1:]}')
    print(f'monster: 血量:{role["monster"][0]}, 各技能伤害:{role["monster"][1:]}')
    print('-' * 50)

    rd = 1
    while role["player"][0] > 0 and role["monster"][0] > 0:
        print(f'round{rd}')

        names = list(role.keys())
        attk = random.choice(names)  # 进攻方
        power_idx = random.randrange(len(role[attk])-1) + 1  # 使用技能的伤害
        power = role[attk][power_idx]
        print(f'进攻方为: {attk}, 选择了技能{power_idx}, 伤害为: {power}')

        names.remove(attk)
        b_attk = names[0]  # 被进攻方
        role[b_attk][0] -= power
        print(f'被进攻方为: {b_attk}, 失去了{power}点血量, 当前血量为: {role[b_attk][0]}')
        print('-'*50)
        rd += 1

    if role["player"][0] <= 0:
        print(f'monster获胜, 剩余血量为{role["monster"][0]}')
    else:
        print(f'player获胜, 剩余血量为{role["player"][0]}')
