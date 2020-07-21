res = 0
def coin(n,s):
    if n<=200:
        if s==200:
            global res
            res+=1
        elif s<200:
            for i in xrange(0,200/n +1):
                if n==1 or n==5 or n==10 or n==50 or n==100:
                    coin(n*2,s+i*n)
                else:
                    coin(n*5 /2,s+i*n) #case of 2 and 20

coin(1,0)
print res +1
