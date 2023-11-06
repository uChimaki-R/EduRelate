def count_chars(s):
    upper = 0
    lower = 0
    digit = 0
    other = 0
    for char in s:
        if char.isupper():
            upper += 1
        elif char.islower():
            lower += 1
        elif char.isdigit():
            digit += 1
        else:
            other += 1
    return upper, lower, digit, other


sts = input().strip()
print(count_chars(sts))
