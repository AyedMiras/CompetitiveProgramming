f = open('/home/master/Desktop/Project Euler/Pb8.txt',"r")
f.seek(0,2)
l = f.tell()
f.seek(0,0)
i=0
maxx=0
while (i<= l-13):
    pr=1
    j=0
    while j!=12:
        try:
            x = int(f.read(1))
            if x:
                pr = pr* x
                j+=1
            else:
                pr =0 #the product is 0 anyway so less instructions
                break
        except ValueError:
            j-=1 #case of \n
    if (pr > maxx):
            maxx = pr
    f.seek(i+1,0)
    i+=1
print maxx
