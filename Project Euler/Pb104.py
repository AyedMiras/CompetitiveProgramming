from sys import exit
from math import log
#to compute the first k digits of n, we use 10**(log10(n)- int(lo10(n)) + k - 1) as 10**k has (k-1) digits and
#log10(n) - int(log10(n)) is the fractional part of log10(n)
def pan(s):
    if "".join(sorted(s)) == "123456789":
        return 1
    return 0
f1 = 1
f2 = 1
cmp = 2
while 1:
    f2 = f2 + f1
    f1 = f2 - f1
    l = log(f2,10)
    cmp += 1
    if pan(str(int(10**(8-int(l) + l)))) and pan(str(f2%10**9)):
        print cmp
        exit(0)
