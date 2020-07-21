fp = open("/home/master/Desktop/Project Euler/Pb11.txt","r")
Mat = [[0 for i in range (20)] for j in range(20)]
i=0
for line in fp:
    Mat[i]=line.split(' ')
    i+=1
maxx =0

for i in range(0,20):
    for j in range(0,17):
        pr1=1
        pr2=1
        for k in range(0,4):
            try:
                pr1 = pr1 * int(Mat[i][j+k]) #two tests hack :D
                pr2 = pr2 * int(Mat[j+k][i])
            except ValueError:
                pass
        if pr1>maxx:
            maxx = pr1
        if pr2>maxx:
            maxx = pr2
        if i<17 and j<17:#descending diagonal
            pr = 1
            for k in range(0,4):
                try:
                    pr = pr * int(Mat[i+k][j+k])
                except ValueError:
                    pass
            if pr>maxx:
                maxx = pr
        if i<17 and j>3: #ascending diagonal
            pr =1
            for k in range(0,4):
                try:
                    pr= pr*int(Mat[i+k][j-k])
                except ValueError:
                    pass
            if pr>maxx:
                maxx= pr

for j in range(0,20):
    for i in range(0,17):
        pr=1
        for k in range(0,4):
            try:
                pr = pr * int(Mat[i+k][j])
            except ValueError:
                pass
        if pr> maxx:
            maxx=pr
print maxx
