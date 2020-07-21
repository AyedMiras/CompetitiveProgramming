from math import sqrt
from math import trunc

def prime(n):
    if n<10:
        if (n==5 or n==2 or n==3 or n==7):
            return 1
        return 0
    if n%2:
        i = 3
        while (i<= trunc(sqrt(n))):
            if not n%i:
                return 0
            i+=2
        return 1
    return 0
s = 2
i = 3
while i<2000000:
    if prime(i):
        s+=i
    i+=2
print s
