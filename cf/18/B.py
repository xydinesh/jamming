#!/usr/bin/python
import sys
(n, d, m, l) = map(int, raw_input().strip().split (" "))
for i in xrange(n):
    k = (((i*m + l)/d) + 1)*d
    if ((k - (i*m + l) < (m - l)) or (i == n - 1)):
        print k
        break
    
        
            
