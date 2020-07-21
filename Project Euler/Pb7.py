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
p=1
i=3
while p!=10001:
    if prime(i):
        p+=1
    i+=2
print i-2
