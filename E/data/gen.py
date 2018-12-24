from random import randint

print(233)

for i in range(233):
    while True:
        n = randint(0, 233)
        if n & 1 == 0:
            break
    print(n)
    a = []
    for i in range(n):
        a.append(randint(-233, 233))
    while True:
        m = randint(-233, 233)
        if m != 0:
            a.append(m)
            break
    print(*a)
