
def remainder(a,b):
    m = 0
    q = 0
    while (m < a):
        m += b
        q += 1
    if m == a:
        return 0
    else:
        return a-(q-1)*b
    
print(remainder(2,5))
