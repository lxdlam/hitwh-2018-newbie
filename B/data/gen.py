from random import randint

CASES = 23333
print(CASES)

for i in range(CASES):
    a = 2**randint(1, 61)
    while a == 1:
        a = 2**randint(1, 61)
    print(a - 1)
