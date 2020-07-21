from sympy import isprime
s = 1
def rotate(l,i):
    return (l[i:] + l[:i])
def good(i):
    for j in xrange(0,len(str(i))):
        if not(isprime(int(rotate(str(i),j)))):
            return 0
    return 1
for i in xrange(3,1000000,2):
    if good(i):
        s+=1
print s
