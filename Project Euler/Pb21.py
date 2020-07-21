from math import trunc
def d(n):
    s = 1
    for i in xrange(2,trunc(n**0.5)):
        if n%i == 0:
            s+= i + n/i
    return s
arr = []
s = 0
for i in xrange(2,10**4):
    aux = d(i)
    if i not in arr and i!=aux and i == d(aux) :
        s += i + aux
        arr.append(aux)
print s
