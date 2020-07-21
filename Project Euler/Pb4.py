def inv(n):
    s = 0
    while (n):
        s= s*10 + n%10
        n = n//10
    return s


def palind(n):
    if inv(n)==n:
        return 1

s =0
for i in range(100,1000):
    j=990
    while (j>99):
        if palind(i*j) and i*j>s:
            s=i*j
        j-=11 #for i*j to be palind, it has to be divisible by 11
print s
