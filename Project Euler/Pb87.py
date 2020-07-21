from sympy.ntheory.generate import primerange as primes
from sympy import isprime
prime1 = [i for i in primes(0,10**4) if i**2 <=5*10**7]
prime2 =[i for i in primes(0,10**3) if i**3 <=5*10**7]
prime3 = [i for i in primes(0,10**2) if i**4 <=5*10**7]
print len(set([i**2+j**3+k**4 for i,j,k in[(i,j,k) for i in prime1 for j in prime2 for k in prime3 if i**2+j**3+k**4 <=5*10**7]]))
