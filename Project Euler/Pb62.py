#combinations of n**3 should have the same length as n**3, so let's compute a matrix of cube with the same length and test
#a better solution
"""cubes = [sorted(str(x**3)) for x in range(10000)]
counts = [cubes.count(x) for x in cubes]
print counts.index(5)**3 """
from sys import exit
def is_permut(n,m):
    s1 = str(n)
    s2 = str(m)
    for i in s1:
        if i in s2:
            s2 = s2.replace(i,"",1)
            s1= s1.replace(i,"",1)
        else:
            return 0
    return 1

cbl = [] #cubes by length
mc = 0 #max cube
cbl.append([])
while 1:
    l = len(cbl)
    while len(str((mc+1)**3)) == l:
        cbl[l-1].append((mc+1)**3)
        mc+=1
    for i in xrange(0,len(cbl[l-1])-1):
        res = [cbl[l-1][i]]
        cmp = 1
        for j in xrange(i+1,len(cbl[l-1])):
            if is_permut(cbl[l-1][i],cbl[l-1][j]):
                res.append(cbl[l-1][j])
                cmp+=1
        if cmp == 5:
            print res
            exit(0)
    cbl.append([])
