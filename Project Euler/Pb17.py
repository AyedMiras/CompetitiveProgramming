elem = {0: '', 1:'one' , 2:'two', 3:'three', 4:'four', 5:'five', 6:'six',7:'seven' ,8:'eight', 9:'nine', 10:'ten',
11:'eleven' , 12:'twelve', 13:'thirteen', 14:'fourteen', 15:'fifteen', 16: 'sixteen' , 17:'seventeen', 18:'eighteen' ,
19:'nineteen',20:'twenty' ,30:'thirty', 40:'forty' , 50:'fifty', 60:'sixty', 70:'seventy' , 80:'eighty' , 90:'ninety' }
s = 0
for i in xrange(1,1000):
    if i>= 100:
        s+= len(elem[i/100])+ len("hundred")
        if i%100 !=0:
            s+=len("and")
    if i%100 <= 20:
        s+=len(elem[i%100])
    else:
        s+=len(elem[i%100 - i%10]) + len(elem[i%10])

print s+ len("onethousand")
