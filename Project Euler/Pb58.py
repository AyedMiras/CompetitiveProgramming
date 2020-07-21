from  __future__ import division
from sympy import isprime
from sys import exit
n = 3
cmp = 0
while 1:
    if isprime(n**2 - n +1):
        cmp +=1
    if isprime(n**2 - 2*n + 2):
        cmp+=1
    if isprime(n**2 - 3*n + 3):
        cmp+=1
    if cmp/(2*n - 1)< 0.1:
        print n
        exit(0)
    n+=2
