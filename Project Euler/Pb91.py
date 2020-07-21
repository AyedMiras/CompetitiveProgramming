def d(x,y):
    return (x**2+y**2)
def right(x1,x2,y1,y2):
    if (x1== x2 and y1==y2) or (x1==0 and y1==0) or (x2==0 and y2==0):
        return 0
    if d(x1,y1) + d(x2,y2) == d(x1-x2 ,y1-y2) or d(x1,y1) + d(x1-x2,y1-y2) == d(x2,y2) or d(x2,y2) + d(x2-x1,y2-y1) == d(x1,y1):
        return 1
    return 0

print len([[x1,y1,x2,y2] for x1,x2,y1,y2 in [(x1,x2,y1,y2) for x1 in xrange(0,51) for x2 in xrange(0,51) for y1 in xrange(0,51) for y2 in xrange(0,51) if right(x1,x2,y1,y2) ]])/2
