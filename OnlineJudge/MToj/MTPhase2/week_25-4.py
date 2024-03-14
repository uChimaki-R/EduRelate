dic = {}

def main():
    num_list = input().strip().split(' ')
    length = len(num_list)
    for num in num_list:
        d = int(num, 2)
        dic[d] = True
    i = 0
    while True:
        if not dic.get(i, False):
            print(bin(i)[2:].zfill(length))
            return
        i += 1


if __name__ == '__main__':
    main()
