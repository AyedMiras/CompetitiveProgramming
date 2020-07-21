from sympy import primerange
from sympy import nextprime
# We're going to understand this algorithm by the exemple (151,157): we compute the first integer for which n*157[0] == 151[0] == 1
#which is 157*3 = 471, now we have found the first last integer, it is now unnecessary to try adding n*157, we can go for n*(1570) because the first last integer is already
#found, let's find the first integer for which n*1570 + 471 [1] == 151 [1] == 5, which is found for n==4 and the number is 6751, doing the same thing for the last integer 7
#we find 38151 :3
def s(p1,p2):
     cmp = p2
     s_p1 = str(p1)
     l = len(s_p1)
     inx = 1
     while inx <= l:
         if str(cmp)[len(str(cmp))-inx] == s_p1[l - inx]:
             inx +=1
             p2 = p2*10
         else:
             cmp += p2
     return cmp
pr = [i for i in primerange(5,10**6 +1) ]
pr.append(nextprime(pr[len(pr)-1])) #the problem states p1<= 10**6 ;)
print sum([s(pr[i],pr[i+1]) for i in xrange(0,len(pr)-1)])
