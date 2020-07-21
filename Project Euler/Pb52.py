from sys import exit
def v(n):
    global s
    aux = s
    if len(s)!=len(str(n)):
        return 0
    for i in str(n):
        if i not in aux:
            return 0
        else:
            aux = aux.replace(i,"")
    return 1
i = 1
while 1:
    s = str(i)
    if v(i) and v(2*i) and v(3*i) and v(4*i) and v(5*i) and v(6*i):
        print i
        exit(0)
    i+=1
