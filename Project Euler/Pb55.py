def lychrel(n):
    for i in xrange(0,50):
        m = n + int(str(n)[::-1])
        if m == int(str(m)[::-1]):
            return 1
        n = m
    return 0
print len([1 for i in xrange(0,10**4) if not lychrel(i)])
