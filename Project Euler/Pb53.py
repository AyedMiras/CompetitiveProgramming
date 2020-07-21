from math import factorial
def comb(n,k):
    return factorial(n) / (factorial(n-k) * factorial(k) )
print len([1 for n,r in [(n,r) for n in xrange(1,101) for r in xrange(1,n+1) if comb(n,r) > 10** 6]])
    
