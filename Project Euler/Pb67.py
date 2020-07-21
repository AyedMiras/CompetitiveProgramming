fp = open("/root/Desktop/Project Euler/Pb067_triangle.txt","r")
lim = 0
arr = []
for line in fp:
    arr.append([int(j) for j in line.split(" ")]) #creating a matrix of the triangle
    lim+= 1
for i in xrange(lim-1,0,-1):
    for j in xrange(0,i):
        arr [i-1][j] += max(arr[i][j],arr[i][j+1]) #every element in the upper line is incremented by max of its two underline ajdactent elements
print arr[0][0] #the max will is eventually the top
