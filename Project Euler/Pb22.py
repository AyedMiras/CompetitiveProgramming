fp = open("/root/Desktop/Project Euler/Pb022_names.txt","r")
arr = []
for line in fp:
    for i in line.split(","):
        arr.append(i[1:len(i)-1])
arr.sort()
s_tot = 0
for i in xrange(0,len(arr)):
    s = 0
    for j in arr[i]:
        s+= ord(j) - ord("A") +1
    s_tot+= s * (i+1)
print s_tot
