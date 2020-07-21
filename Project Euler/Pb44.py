#knowing n, the lowest difference for all k< n is pen(n)- pen(n-1)
#since pen(n) - pen(n-1) = 3n+1 is an increasing serie, then all we need is to find the D (haha :p)
#from which pen(m)- pen(m-1) > D, that D is assured to be the minimum difference. ;)


from sys import exit
def pen(n):
    return n*(3*n - 1)/2
def is_pen(x):
    if (24*x + 1)**0.5 == int ((24*x + 1)**0.5) and (24*x + 1)**0.5 % 6 == 5:
        return 1
    return 0
found = 0
d = 0
i = 2
while (not found or pen(i)-pen(i-1) <= d):
    n = pen(i)
    for j in xrange(i-1,0,-1):
        m = pen(j)
        if is_pen(n+m) and is_pen(n-m):
            if not found:
                found = 1
            if d < n-m:
                d = n-m
    i+=1
print d, i
