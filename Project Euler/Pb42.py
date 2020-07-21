from math import trunc
from math import sqrt
f = open('/root/Desktop/Project Euler/Pb42_words.txt',"r")
x=0
def tr(n):
    x = trunc(sqrt(2*n))
    if x*(x+1)//2 == n:
        return 1
    return 0
for line in f:
    l = line.split(",")
    for word in l: #can't transform file to string so hack that with for :D
        print word
        s = 0
        for i in xrange(1,len(word)-1):
            s+= ord(word[i]) - ord('A') + 1
        if tr(s):
            x+=1
print x
