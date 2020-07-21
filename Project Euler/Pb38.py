def pan(s):
    for j in xrange(1,10):
        if str(j) not in s:
            return 0
    return 1
def cond(i):
    s = str(i)
    if s[0]!= "9": #Largest number should start with nine :p
        return 0
    cmp = 2
    while len(s)<9:
        s = s + str(i*cmp)
        cmp+=1
    if len(s) ==9 and pan(s):
        return int(s)
    return 0

print max([cond(i) for i in xrange(0,10**5) ])
