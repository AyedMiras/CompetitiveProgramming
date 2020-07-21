from math import sqrt
from math import trunc
n = 3
while 1:
    tr = n*(n+1)//2
    div = 2
    for i in range(2,trunc(sqrt(tr))):
        if not tr%i:
            div+=2
    if div>=500:
        break
    n+=1
print tr
