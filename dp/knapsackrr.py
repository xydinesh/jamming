#!/usr/bin/python
import sys

n = int(sys.stdin.next())
for ii in xrange(n):
    b = []
    e = []
    c = int(sys.stdin.next().strip());
    w = map(int, sys.stdin.next().strip().split(" "))
    p = map(int, sys.stdin.next().strip().split(" "))
    
    b = [0]*(c + 1)
    b[0] = 0

    e = ["0"]*(c + 1)

    for i in xrange (c + 1):
        for j in xrange (len(w)):
            if ((i >= w[j]) and (b[i - w[j]] + p[j] > b[i])):
                b[i] = b[i - w[j]] + p[j]
                e[i] = e[i - w[j]] + "," + str(w[j])+":"+str(p[j])

    print "Case #%d: [%s] %d" % (ii+1, e[c], b[c])
    
    





