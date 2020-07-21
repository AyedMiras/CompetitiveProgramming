def is_abun(n):
    return 1 + sum(set(i+n/i for i in xrange(2,int(n**0.5) +1) if not n%i)) > n
abun = [i for i in xrange(12,28113) if is_abun(i)]
print 28123*28124/2 - sum(set([abun[i]+abun[j] for i,j in [(i,j) for i in xrange(0,len(abun)) for j in xrange(i,len(abun)) if abun[i]+abun[j] < 28124 ]]))
