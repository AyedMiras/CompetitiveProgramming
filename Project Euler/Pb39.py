from sys import exit
arr = [(a*a+b*b)**0.5 + a +b for a,b in [(a,b) for a in xrange(1,500) for b in xrange(a+1,501) if (a*a+b*b)**0.5 +a+b <=1000 and (a*a+b*b)**0.5 == int((a*a+b*b) **0.5) ]]
arr.sort()
m = max(set([arr.count(arr[i]) for i in xrange(0,len(arr))]))
print list(set([x for x in arr if arr.count(x) == m]))
