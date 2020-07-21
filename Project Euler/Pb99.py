from math import log
fp = open("/root/Desktop/Project Euler/Pb099_base_exp.txt","r")
m = max(x*log(y) for y,x in [(int(line.split(",")[0]),int(line.split(",")[1])) for line in fp])
cmp =0
fp.seek(0,0)
for line in fp:
    cmp+=1
    if int(line.split(",")[1])*log(int(line.split(",")[0])) == m:
        print cmp
        break
