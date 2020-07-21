f1 = 1
f2 = 2
n = 3
while (len(str(f2))<10**3):
    f2 = f1 + f2
    f1 = f2 -f1
    n+=1
print n
