#!/usr/bin/python
import sys

n = int(sys.stdin.next())
for ii in xrange(n):
    ans = {}
    b = []

    c = int(sys.stdin.next().strip());
    w = map(int, sys.stdin.next().strip().split(" "))
    p = map(int, sys.stdin.next().strip().split(" "))

    
    b = [0]*(len(p) + 1)
    for i in xrange(len(p) + 1):
        b[i] = [0]*len(xrange(c + 1))

    for i in xrange (c + 1):
        b[0][i] = 0

    for i in xrange (len(p) + 1):
        b[i][0] = 0

    for i in xrange (len(p) + 1):
        for j in xrange (c + 1):
            if j >= w[i - 1]:
                if p[i - 1] + b[i - 1][j - w[i - 1]] > b[i - 1][j]:
                    b[i][j] = p[i - 1] + b[i - 1][j - w[i - 1]]
                else:
                    b[i][j] = b[i - 1][j]
            else:
                b[i][j] = b[i - 1][j]

    k = c
    i = len(p)
    while (i >= 0 and k >= 0):
        if (b[i][k] != b[i - 1][k]):
            k -= w[i - 1]
            ans[p[i - 1]] = w[i - 1]
        i -= 1
        

    print "Case #%d: %s %d" % (ii+1, str(ans), b[len(p)][c])
    
    





