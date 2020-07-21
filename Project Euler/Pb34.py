from math import factorial as f
n = 1
while 10**(n-1) < n*f(9):
    n+=1
print sum([ i for i in xrange(0,10**(n-1)) if i == sum([f(int(j)) for j in str(i)])]) - 3
