from sympy import isprime
from itertools import permutations
from sys import exit
for i in xrange(1488,10000):
    if isprime(i):
        for j,k in [(j,k) for j in permutations(str(i)) for k in permutations(str(i)) if j!=k]:
            a = max(int("".join(j)),int("".join(k)))
            b = min(int("".join(j)),int("".join(k)))
            if a!=b and i!=a and b!=i and isprime(a) and isprime(b) and abs(a-b)==abs(b-i):
                print str(i)+str(b)+str(a)
                exit(0)
