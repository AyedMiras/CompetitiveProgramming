from sympy import isprime
def tru_pr(n):
    s1 = str(n)
    s2 = s1
    for i in xrange(0,len(str(n))):
        if not (isprime(int(s1)) and isprime(int(s2))):
            return 0
        s1 = s1[1:]
        s2 = s2[:len(s2)-1]
    return 1
cmp = 0
s = 0
i = 11
while cmp<11:
    if tru_pr(i):
        cmp+=1
        s+=i
    i+=2
print s
