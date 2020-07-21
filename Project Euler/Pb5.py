import math
def prime(n):
    if (n<10):
        if (n==2 or n==3 or n==5 or n==7):
            return 1
        return 0
    if n%2:
        i =3
        while (i<=math.trunc(math.sqrt(n))): #this condition is valid only when sqrt(n)>3
            if (not n%3):
                return 0
            i+=2
        return 1
    return 0
p =1
n = 20 #choose any n as the max number
for i in range(2,n+1):
    if (prime(i)):
        j= 1
        while (j*i<n+1):
            j = j*i
        p = p*j
print p
