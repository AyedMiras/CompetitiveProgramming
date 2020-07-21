s1=0
s2=0
for i in range(1,101):
    s1 = s1+i
    s2 = s2+ i*i
s1*= s1
print s1 - s2
