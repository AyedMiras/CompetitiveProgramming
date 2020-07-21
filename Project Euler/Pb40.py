from numpy import product
s = ""
i = 1
while len(s) < 10**6:
    s+= str(i)
    i+=1
print product([int(s[10**i -1]) for i in xrange(0,7) ])
