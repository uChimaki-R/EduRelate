def prime_pairs(n, k):
    def is_prime(num):
        if num < 2:
            return False
        for i in range(2, int(num ** 0.5) + 1):
            if num % i == 0:
                return False
        return True

    primes = [i for i in range(2, n + 1) if is_prime(i)]
    pairs = [(p1, p2) for i, p1 in enumerate(primes[:-1]) for p2 in primes[i + 1:] if abs(p1 - p2) == k]
    pairs.sort(key=lambda x: x[0])
    return pairs


lis = input().strip().split(' ')
n = int(lis[0])
k = int(lis[1])
ps = prime_pairs(n, k)
if len(ps):
    for st, ed in ps:
        print(st, ed)
else:
    print('empty')
