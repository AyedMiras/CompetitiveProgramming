fp = open("/root/Desktop/Project Euler/Pb081_matrix.txt","r")
mat = []
for line in fp:
    s = line[:len(line)-1] #to remove the /n at the end
    mat.append([int(i) for i in s.split(",")])
print mat
for i in xrange(79,-1,-1):
    for j in xrange(79,-1,-1):
        if i==79:
            if j!=79:
                mat[i][j]+= mat[i][j+1]
        else:
            if j!=79:
                mat[i][j]+= min(mat[i+1][j],mat[i][j+1])
            else:
                mat[i][j]+=mat[i+1][j]
print mat[0][0]
