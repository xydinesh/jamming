#!/usr/bin/python
import sys

n = int(sys.stdin.next().strip())
x = [i for i in xrange(n) if (i%3 == 0) or (i % 5 == 0)]
print sum(x)

