fp= open("/home/master/Desktop/Project Euler/Pb13.txt","r")
s = 0
for line in fp:
    try:
        s = (s+ int(line ))
    except ValueError:
        pass    
print str(s)[:10]
