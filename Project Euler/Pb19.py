r = 1 #r represents the remainder
s = 0
mon_day = {1:31,2:28,3:31,4:30,5:31,6:30,7:31,8:31,9:30,10:31,11:30,12:30} #just to illustrate months and days
for i in xrange(1900,2001):
    for j in mon_day.items():
        if not i%4 and j[0] ==2: #leap year and february
            r = (r+j[1]+1)%7
        else:
            r = (r+j[1])%7
        if r==0 and i>1900: #because we know that 1 jan 1900 is monday but the problem calculations start from 1901 :3
            s+=1
print s
