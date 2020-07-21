from sympy import isprime
from sys import exit
i = 3
while 1:
    v = 1
    if not isprime(i):
        for j in xrange(2,i):
            if isprime(j) and ((i-j)/2)**0.5 == int (((i-j)/2)**0.5):
                v = 0
                break
        if v:
            print i
            exit(0)
    i+=2
