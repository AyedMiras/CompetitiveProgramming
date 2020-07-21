f1=1
f2=2
s=2
while f2<4000000:
    f2 = f1+f2
    f1 = f2-f1
    if (not f2%2):
        s+=f2
print s
