#!/usr/bin/python
import sys

def proc_one(para, pixel):
    cost = 0
    if ((para[0] == 0) or (para[1] == 0)):
        return cost
    d = pixel[0]
    if (d > para[2]):
        ch = d - para[2]
        if (para[2] > 0):
            ins = (d/para[2])*para[1]
        else:
            ins = d*para[1]
        de = para[0]
        cost += min([ch,ins,de])
    return cost

def proc_two(para, pixel):
    cost = 0
    for j in xrange(para[3] - 1):
        if ((para[0] == 0) or (para[1] == 0)):
            break
        d =  abs(pixel[j] - pixel[j + 1])
        if (d > para[2]):
            ch = d - para[2]
            if (para[2] > 0):
                ins = (d/para[2])*para[1]
            else:
                ins = d*para[1]
            de = para[0]*2
            cost += min([ch,ins,de])
    return cost


def proc_three(para, pixel):
    cost = 0
    for j in xrange(para[3] - 1):
        if ((para[0] == 0) or (para[1] == 0)):
            break

        d =  abs(pixel[j] - pixel[j + 1])
        if (d > para[2]):
            ch = d - para[2]
            if (para[2] > 0):
                ins = (d/para[2])*para[1]
            else:
                ins = d*para[1]
            de = para[0]
            if ((de < ch) and (de < ins)):
                dd = abs(pixel[1] - pixel[2])
                if (dd > para[2]):
                    pixel[j + 1] = pixel[j]
                else:
                    pixel[j] = pixel[j + 1]
                cost += de
            else:
                cost += min([ch,ins])
    return cost


n = int(sys.stdin.next())
for i in xrange(n):
    para = map(int, sys.stdin.next().strip().split(" "))
    pixel = map(int, sys.stdin.next().strip().split(" "))
    cost = 0
    if (para[3] == 3):
        cost = proc_three(para, pixel)
    elif(para[3] == 2):
        cost = proc_two (para, pixel)
    else:
        cost = proc_one (para, pixel)
    

    print "Case #%d: %d" % ( i + 1, cost)
            
            
    
        
        
