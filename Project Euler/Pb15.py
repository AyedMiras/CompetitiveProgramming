T=[[0 for i in range(0,22)] for j in range(0,22)]
def path(i,j,maxx,T):
    if (i>maxx or j>maxx):
        return 0
    if (i==maxx and j ==maxx):
        return 1
    if not T[i][j+1]:
        T[i][j+1]= path(i,j+1,maxx,T)
    if not T[i+1][j]:
        T[i+1][j]=path(i+1,j,maxx,T)
    return T[i+1][j] + T[i][j+1]
print path(0,0,20,T)
