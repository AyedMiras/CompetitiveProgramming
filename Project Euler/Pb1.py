s=0
for i in range(3,1000):
    if ( not i%3 or not i%5):
        s=s+i
print(s)
