max=150000 #of course assuming a limit
n_factor = [0]*max

for i in range(2,max):
    if n_factor[i] == 0 : #aka prime
    	for j in range(2*i,max,i):
            n_factor[j] += 1

goal = [4]*4

for i in range(2,max):
     if n_factor[i:i+4] == goal:
        print i
        break
