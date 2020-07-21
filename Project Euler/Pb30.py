n = 1
while 10**(n-1) < n*9**5: #si p contient n chiffres alors   10**n-1 <=p<=n*9**5
    n+=1
print sum([i for i in xrange(0,10**(n-1)) if i==sum([int(j)**5 for j in str(i)])]) -1
