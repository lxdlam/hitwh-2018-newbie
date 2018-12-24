from random import randint, shuffle


def getPtt(s, p):
    if s >= 10000000:
        return p + 2
    if s >= 9950000:
        return p + 1.5 + 1.0 * (s - 9950000) / 100000
    if s >= 9800000:
        return p + 1 + 1.0 * (s - 9800000) / 400000
    ret = p + 1.0 * (s - 9500000) / 300000
    return (0.0 if ret <= 0 else ret)


def genTest(sz, slo, shi, plo, phi):
    se = set()
    print(sz)
    re = []

    for _ in range(sz):
        while True:
            ts = randint(slo, shi)
            tp = randint(plo, phi)
            ptt = int(getPtt(ts, tp / 10) * int(1e8))
            if not se.issuperset({ptt}):
                se.add(ptt)
                re.append((ts, tp))
                break

    # print(len(se), file=sys.stderr)

    for _ in range(10):
        shuffle(re)

    for s, p in re:
        print(s, f"{p//10}.{p%10}")


# print(1)

# # for _ in range(100):
# genTest(50, 0, 10000000, 10, 120)

# for _ in range(20):
#     genTest(1000, 0, 10000000, 10, 120)
# for _ in range(20):
#     genTest(1000, 9000000, 10000000, 10, 120)
# for _ in range(20):
#     genTest(1000, 0, 10000000, 110, 120)
# for _ in range(20):
#     genTest(1000, 5000000, 10000000, 60, 120)
# for _ in range(20):
#     genTest(1000, 9500000, 10000000, 110, 120)

# This section is sample generator

s = set()

A = []
B = []
Bptt = []

for _ in range(30):
    while True:
        ts = randint(8000000, 10000000)
        tp = randint(90, 120)
        ptt = int(getPtt(ts, tp / 10) * int(1e8))
        if not s.issuperset({ptt}):
            s.add(ptt)
            B.append((ts, tp))
            Bptt.append(ptt)
            break

Bptt = sorted(Bptt)

for _ in range(20):
    while True:
        ts = randint(0, 10000000)
        tp = randint(10, 120)
        ptt = int(getPtt(ts, tp / 10) * int(1e8))
        if not s.issuperset({ptt}) and ptt < Bptt[0]:
            s.add(ptt)
            A.append((ts, tp))
            break

assert ((len(A) + len(B)) == 50)

for _ in range(100):
    shuffle(A)
    shuffle(B)

print("1\n50")

for i in range(10):
    s, p = A[i]
    print(s, f"{p//10}.{p%10}")

for s, p in B:
    print(s, f"{p//10}.{p%10}")

for i in range(10):
    s, p = A[i + 10]
    print(s, f"{p//10}.{p%10}")