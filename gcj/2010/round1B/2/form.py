#!/usr/bin/python
import sys

n = int(sys.stdin.next().strip())
for i in xrange(n):
    x = sys.stdin.next().strip()
    print "Case #%d: %s" % (i + 1, x)
