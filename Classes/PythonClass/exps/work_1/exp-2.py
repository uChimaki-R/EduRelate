import random


if __name__ == '__main__':
    store = {"apple": 1, "banana": 2, "watermelon": 3}
    stock = {"pear", "cherry", "apple", " orange"}
    print(f'store: {store}')
    print(f'stock: {stock}')

    print('-'*80)

    num = len(stock) // 2
    fruits = random.choices(list(stock), k=num)
    # print(fruits)

    for fruit in fruits:
        cnt = random.randint(1, 10)
        if fruit in store.keys():
            store[fruit] += cnt
        else:
            store[fruit] = cnt
    print(f'store: {store}')

    store_list = [(a, b) for a, b in zip(store.keys(), store.values())]
    store_sorted = sorted(store_list, key=lambda x: -x[1])
    print(f'store_sorted:{store_sorted}')
