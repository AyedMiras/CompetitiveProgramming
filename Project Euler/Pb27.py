from sympy import isprime
def c_prime(a,b):
    n = 0
    m = 0
    while 1:
        if isprime(n**2 + a*n + b):
            m+= 1
            n+=1
        else:
            global maxx
            global max_prod
            if m > maxx:
                maxx = m
                max_prod = a*b
                return 1
            return 0
maxx = 0
max_prod = 1
for a in xrange(-10**3 +1, 10**3):
    b = maxx
    while b < 10**3 +1:
        if c_prime(a,b) and b < maxx: #because b^2 + a*b + b is divisble by b, hence max of primes is b.
            b = maxx
        else:
             b+=1
print max_prod
