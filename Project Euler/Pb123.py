from sympy import prime
from sympy import nextprime
from sys import exit
""" by doing the math we find out that when n=2p , the remainder is 2, otherwise it's 2*n*Pn :D, alse, 2*n < Pn
for big n """
n = 7037
p = prime(7037)
while 1:
    if (2*p*n) - 10**10 >0:
        print n, 2*(prime(n-2))*(n-2)
        exit(1)
    p = nextprime(nextprime(p))
    n+=2
