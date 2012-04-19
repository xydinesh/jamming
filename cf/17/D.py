#!/usr/bin/python
import sys
import math

b,n,c = map (int, sys.stdin.next().strip().split (" "))
x = (n - 1)*math.log(b) + math.log(b - 1)
k = int(math.exp(x)) % c
if (k == 0):
    print c
else:
    print k
