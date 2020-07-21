num = [0 for i in xrange(567)] """we only need to compute 567 values as 9*9*7 == 567"""
num[0] = -1
num[88] = 1
def sq_sum(n):
    return sum([int(i)**2 for i in str(n)])
def chain(n):
    global num
    s = sq_sum(n+1)-1
    if not num[s]:
        num[s]= chain(s)
    return num[s]
s=0
for i in xrange(10**7):
    if i<567 and num[i]==1:
        s+=1
    elif chain(i) == 1:
        s+=1
print s
