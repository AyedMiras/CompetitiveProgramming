from sympy import nextprime
""" The algorithm is based on totient formula , minimizing phi(n) means maximizing number of different prime factors !"""
n = 2
p = 2
while (p< 10**6):
    n = nextprime(n)
    p *= n
print p/n
