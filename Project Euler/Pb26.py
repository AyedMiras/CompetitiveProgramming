#the principle is elementary division, if a remainder is repeated than it is cyclic


def cycle(n):
    rem = [1]
    d = 1
    while 1:
        d = (d%n)*10
        if d%n in rem:
            return len(rem)
        rem.append(d%n)

print max( ((cycle(i),i) for i in xrange(1,1000) ), key = lambda item:item[0] )[1]
