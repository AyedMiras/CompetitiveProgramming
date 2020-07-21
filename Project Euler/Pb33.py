from __future__ import division
def pgcd(a,b):
    if b==0:
        return a
    return pgcd(b,a%b)
num = 1
den = 1

for i in xrange(10,99):
    for j in xrange(i+1,100):
        if  (str(i)[0] == str(j)[1] or str(i)[1] == str(j)[0]):
            if (int(str(j)[1]) != 0  and int(str(i)[0])/int(str(j)[1]) == i/j) or (int(str(j)[0]) !=0 and int(str(i)[1])/int(str(j)[0]) == (i/j)):
                num*= i
                den*=j
                print i,j
print num,den
d = pgcd(max(num,den),min(num,den))
print den/d
