from math import factorial as f
def loop(n):
    global loo
    arr = [n]
    for j in xrange(1,60):
        s = sum([f(int(i)) for i in str(n)])
        if s not in arr :
            arr.append(s)
            n = s
        else:
            return 0
    return 1
loo = []
print len([1 for i in xrange(0,10**6) if loop(i)])
