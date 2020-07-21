def ctz(n):
    if n==1:
        return 1
    if not n%2:
        return 1+ctz(n//2)
    return 1+ctz(3*n+1)
maxx=0
larg=1
for i in range(1,1000000):
    terms = ctz(i)
    if terms >maxx:
        maxx=terms
        larg=i
print larg
