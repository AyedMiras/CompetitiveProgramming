def bouncy(n):
    s = str(n)
    if len(s)<3:
        return 0
    if s[1] == s[0]:        #if the two starting character are the same
        return bouncy(int(s[1:]))
    if s[1] < s[0]:         #for doing the increasing and decreasing in one algorithm
        s = s[::-1]
    for i in xrange(1,len(s)):
        if int(s[i]) < int(s[i-1]):
            return 1
    return 0

b_cmp = 0.0
i = 99
while (b_cmp / i < 0.99):
    i+=1
    if bouncy(i):
        b_cmp+=1
print i
