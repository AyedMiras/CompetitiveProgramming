sqr = [i*i for i in range(0,10**4)] #list of squares to be used
res = [] #res for result
for x in xrange(1,10**4-2):
    b = 0 #b for break
    for y in xrange(x+2,10**4):
        s = 0
        for i in sqr[x:y]:
            s += i
            if s >= 10**8:
                b = 1
                break
        if b:  #if breaked, it is unnecessary to try others y
            break
        if s < 10**8 and str(s) == str(s)[::-1]:
            res.append(s)
print sum(set(res)) #set to eliminate redundancies because a number can have more than one consecutive squares sum expression
