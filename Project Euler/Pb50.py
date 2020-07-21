from sympy import isprime

def prime_list(n):
    arr = []
    for i in xrange(2,n):
        if isprime(i):
            arr.append(i)
    return arr

arr = prime_list(1000000)
maxx = 0
res = 0
i = 0
l= len(arr)
while (i< l-maxx):
    s = 0
    cmp = 0
    for j in xrange(i,l):
        s = s+arr[j]
        cmp +=1
        if s>1000000:
            break
        if cmp > maxx and isprime(s):
            maxx = cmp
            res = s
    i+=1
print res,maxx
