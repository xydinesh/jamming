#!/usr/bin/python
import sys

n = int(sys.stdin.next().strip())
ii = 3;
n -= 1
while(n >= 1):
    for i in xrange(2, ii + 1):
        if ((ii % i) == 0):
            break

    if (i == ii):
        n -= 1
    ii += 1

print ii - 1

