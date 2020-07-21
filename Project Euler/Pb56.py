print max([ sum(int(i) for i in str(a**b)) for a,b in [(a,b) for a in xrange(0,100) for b in xrange(0,100)]])
