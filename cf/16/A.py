#!/usr/bin/python
import sys
x = "YES"
(n,m) = map(int, sys.stdin.next().strip().split (" "))
col = [0]*n
for ii in xrange(n):
    col[ii] = sys.stdin.next().strip()

for i in xrange(n):
    io = int(col[i][0])

    for j in xrange(m):
        ij = int (col[i][j])
        if (ij != io):
            x = "NO"
            break

    if (i > 0):
        if ( io == int(col[i - 1][0])):
            x =  "NO"
            break

    if not ((io >= 0) and (io < 10)):
        x = "NO"
        break
        

print x
        
    
