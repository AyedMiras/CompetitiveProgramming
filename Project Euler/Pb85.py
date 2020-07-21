def rec(x,y):
    return (x*(x+1)*y*(y+1))/4 """ rec(x,y) = for i in xrange(x) for j in xrange(y): cmp+= (x-i)*(y-j) , with simple sum math we find the formula """
res= min([ (i,j) for i,j in [(i,j) for i in xrange(1,2*10**3+1) for j in xrange(i,2*10**3+1) if abs(rec(i,j) - 2*10**6) < 1000] ],key =lambda (x,y):abs(2*10**6 - rec(x,y)))
print res[0]*res[1]
