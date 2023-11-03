import distance


point1 = map(int, input('请输入第一个点的坐标, 以空格为分隔:').split())
point2 = map(int, input('请输入第二个点的坐标, 以空格为分隔:').split())
dis_x, dis_p = distance.distance(*point1, *point2)
print(f'x轴方向距离为: {dis_x}, 两点之间距离为: {dis_p}')
