from itertools import permutations
from sympy import prime
def verif(n):
    if len(str(n))!=10:
        return 0
    for i in xrange(1,8):
        if int(str(n)[i:i+3])%prime(i):
            return 0
    return 1
print sum([int("".join(i)) for i in permutations("0123456789") if verif(int("".join(i)))])
