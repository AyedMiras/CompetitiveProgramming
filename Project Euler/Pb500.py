from sympy import prime
from math import log
from sys import exit
""" The algorith is based on the idea that if n= p1^a1 * p2^a2 *... pk^ak then div(n) = (a1+1)(a2+1)(a3+1)..(ak+1). div(n) = 2**500500 then ai = 2^q - 1.
the basic idea is to compute the first 500500 prime and then eliminate the last ones and increment the power of the firsts when possible. """
n = 500500
arr = [ [prime(i+1),1] for i in xrange(0,n)]
i = n-1
j = 0
while 1:
    if j==i:
        p = 1
        for k in xrange(0,i+1):
            p = (p*(arr[k][0]**(arr[k][1])) )%500500507
        print p
        exit(0)
    if arr[j][0]**(arr[j][1]+1)< arr[i][0]:
        arr[j][1] = arr[j][1]*2 +1 #the power incrementation is a power of 2 so the div(n) remain 2**500500
        i-=1
        j = 0
    else:
        j+=1
