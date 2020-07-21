""" #the 3 lines solution :D
from sympy import isprime
from itertools import permutations
print max (int("".join(i)) for i in permutations('1234567') if isprime(int("".join(i))))
"""


import sys
from math import sqrt
from math import ceil
s = "7654321"
def prime(x):
    if not (x%2):
        return 0
    for i in xrange(3,int(ceil(sqrt(x))),2):
        if not (x%i):
            return 0
    return 1
def swap(s,i,j): #since strings are immutable in python, we need to use lists and return the resulting string
    if i!=j:
        lis = list(s)
        aux = lis[i]
        lis[i] = lis[j]
        lis[j] = aux
        return ("".join(lis))
    return s
def comb(n, s):
    if n < len(s):
        for i in xrange(n,len(s)):
            s2 = swap(s,n,i)
            comb(n+1,s2)
            if n == len(s)-1 and prime (int(s2)): #we test for n so we don't have to test the same number twice
                print s2
                sys.exit(0)
    else:
        print s

# a pandigital can only be prime if it has 7,4 or 1 digits, we can exculde 1.
comb(0,s) #test 7 digits numbers
s = s[2:]
comb(0,s) #test 4 digits numbers
