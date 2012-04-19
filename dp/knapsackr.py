#!/usr/bin/python
import sys
from operator import itemgetter

def lsize(a,b):
    if (a > b):
        return 1
    return 0

n = int(sys.stdin.next())
for ii in xrange(n):
    ans = []
    b = 0
    wp = {}

    c = int(sys.stdin.next().strip());
    w = map(int, sys.stdin.next().strip().split(" "))
    p = map(int, sys.stdin.next().strip().split(" "))
    
    for i in xrange(len(p)):
        wp[w[i]] = p[i]
    
    size = c;
    
    swp = sorted(wp.items(), key=itemgetter(1))
    swp.reverse()
    while (size > 0):
        l = [i for i in w if i < size]
        flag = 0
        for i in xrange(len(swp)):
            if swp[i][0] < size:
                size -= swp[i][0]
                ans.append(swp[i])
                flag = 1
                break

        if flag == 0:
            break

    for i in xrange(len(ans)):
        b += ans[i][1]
        
    print "Case #%d: %s %d" % (ii+1, str(ans), b)
    
    





