def WAYS():
    ways = [  [ 0 for i in xrange(100)] for j in xrange(101) ]
    for i in range(100):
        ways[0][i]=1
    for i in range(1,101):
        for j in range(1,100):
            x=ways[i - j][j] if i-j >=0 else 0
            y=ways[i][j-1] if j>=1 else 0
            ways[i][j]=x+y
    return ways[100][99]
print WAYS()
