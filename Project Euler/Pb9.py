from math import sqrt
# a<333 and b<500 proven by pen and paper
for a in range(0,334):
    for b in range(334-a,500):
        if a+b+sqrt(a*a+b*b) == 1000:
            print a*b*sqrt(a*a+b*b)
            break
