#!/usr/bin/python
import sys

(n,t) = map(int, sys.stdin.next().strip().split (" "))
di = {}
pl = {}
for ii in xrange(n):
    l = [0.0]*2
    (xi,ai) = map(int, sys.stdin.next().strip().split (" "))
    l[0] = xi - float(ai)/float(2)
    l[1] = xi + float(ai)/float(2)
    di[ii] = l

places = 0
for ii in xrange(n):
    xii = [0.0]*2
    x = di[ii]
    xii[0] = x[0] - t
    xii[1] = x[1] + t
    flag1 = 0
    flag2 = 0
    c1 = xii[0] + float(t)/float(2)
    c2 = xii[1] - float(t)/float(2)
    for jj in xrange(n):
        if (ii == jj):
            continue
        y = di[jj]

        if ((y[0]  <= xii[0]) and (xii[0] <= y[1])):
                flag1 = 1


        if ((y[0]  <= xii[1]) and (xii[1] <= y[1])):
                flag2 = 1


    if (flag1 == 0):
        if not (pl.has_key(c1)):
            if not ((c1 < -1000) or (c1 > 1000)):
                places += 1
                pl[c1] = 1

    if (flag2 == 0):
        if not (pl.has_key(c2)):
            if not ((c2 < -1000) or (c2 > 1000)):
                places += 1
                pl[c2] = 1
                

print places



