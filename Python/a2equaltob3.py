def answer(n):
    res = []
    t = 1
    while len(res) != n:
        for a in range(t):
            for b in range(t):
                if a**2 == b**3:
                    r = [a,b]
                    if r not in res:
                        res.append(r)
        t += 1
    return res

print(answer(10))