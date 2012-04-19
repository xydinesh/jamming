#!/usr/bin/python
import sys
import string

v = map(int, sys.stdin.next().strip().split(" "))
n = v[0]
m = v[1]
b = [[]]*n
dim = [0]*4
dim[0] = m - 1
dim[2] = n - 1

for ii in xrange(n):
    l = sys.stdin.next().strip()
    b[ii] = l[:]

    x = string.find(l, '*')
    if ((dim[0] > x) and (x >= 0)):
        dim[0] = x

    x = string.rfind(l, '*')
    if (dim[1] < x) and (x >= 0):
        dim[1] = x

    if (string.find(l, '*') >= 0):
        if dim[2] > ii:
            dim[2] = ii

        if dim[3] < ii:
            dim[3] = ii

for i in xrange(dim[2],dim[3]+1):
    y=""
    for j in xrange (dim[0], dim[1] + 1):
         y += b[i][j]
    print y

