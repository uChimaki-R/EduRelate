m = int(input())
for fir in range(m, 0, -1):
    for spc in range(fir, m):
        print('          ', end='')
    for sec in range(fir, 0, -1):
        print('{}*{}={:2d}    '.format(fir, sec, fir * sec), end='')
    print()
