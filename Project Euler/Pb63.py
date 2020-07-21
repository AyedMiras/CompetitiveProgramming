from math import ceil
# p = sum(ai * 10 ** i) for i in xrange(0,n) = m**n ; with n = len(str(p)); we have 10**(n-1) <= p < 10**n;
# then 10**(n-1)/n <=m<=9 ; for n>=22, we have 10**(n-1)/n > 9; so 22 is the maximum limit
print sum([sum([1 for i in xrange(int(ceil(10**((n-1.0)/n))),10) ]) for n in xrange(1,22)]) 
