import math


def distance(*args):
    if len(args) % 2 != 0:
        raise ValueError("请输入偶数个坐标值")

    half = len(args)//2

    x_fir = args[0]
    x_sec = args[half]
    dis_x = x_sec - x_fir

    dis_p = math.sqrt(sum((args[half + i] - args[i]) ** 2 for i in range(0, half)))

    return dis_x, dis_p
