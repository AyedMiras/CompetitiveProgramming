n =  600851475143
p = 3
while p<n:
    if not n%p:
        n=n/p
        p=1
    p+=2
print n
