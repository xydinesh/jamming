#!/usr/bin/python
import sys

def proc_swap (para, x, v):
    li = []
    time = []
    cost = 0
    count = 0
    tot = 0

    for i in xrange(para[0]):
        t = float(para[2] - x[i])/float(v[i])
        time.append(t)

    for i in xrange(len(time)):
        if (not (time[i] > para[3])):
            li.append(time[i])
    
    if (len(li) < para[1]):
        return -1

    for i in reversed(xrange(len(time))):
        if not (time[i] > para[3]):
            cost += count
            tot += 1 
        else:
            count += 1

        if not (tot < para[1]):
            break

    return cost

n = int(sys.stdin.next())
for i in xrange(n):
    cost = 0
    para = map(int, sys.stdin.next().strip().split(" "))
    x = map(int, sys.stdin.next().strip().split(" "))
    v = map(int, sys.stdin.next().strip().split(" "))

    cost = proc_swap(para, x, v)

    if (cost == -1):
        print "Case #%d: IMPOSSIBLE" % ( i + 1)
    else:
        print "Case #%d: %d" % ( i + 1, cost)
        
            
            
    
        
        
