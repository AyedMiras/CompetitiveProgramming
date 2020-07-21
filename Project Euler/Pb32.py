from math import trunc
from math import sqrt
def pan(n):
    arr = range(1,10)
    for i in n:
        if int(i) in arr:
            arr.remove(int(i))
        else:
            return 0
    if not (len(arr)):
        return 1
    return 0
s = 0
for p in xrange(1,9877):
    i = 1
    cnd = trunc(sqrt(p))
    while i <= cnd and len(str(i) + str(p//i) + str(p)) < 10:
        if p%i == 0 and pan(str(i) + str(p//i) + str(p)):
            s+=p
            break
        i+=1
print s
