from math import sqrt
def tr(n):
    return n*(n+1)/2
def pen(n):
    return n*(3*n-1)/2
def hexx(n):
    return n*(2*n-1)
n = 286
x = tr(n)
while ((1+sqrt(24*x+1))/6)!= int((1+sqrt(24*x+1))/6) or (1+sqrt(8*x+1))/4!= int((1+sqrt(8*x+1))/4):
    n+=1
    x = tr(n)
print x
