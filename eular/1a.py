#!/usr/bin/python
import sys

def sum_div3(n):
    k = int(n/3)
    return 3*k*(k+1)/2

def sum_div5(n):
    k = int(n/5)
    return 5*k*(k+1)/2

def sum_div15(n):
    k = int(n/15)
    return 15*k*(k+1)/2
    


n = int(sys.stdin.next().strip())
n -= 1
print (sum_div3(n) + sum_div5(n) - sum_div15(n))

