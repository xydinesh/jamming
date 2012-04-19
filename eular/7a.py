#!/usr/bin/python
import sys

def isprime(n):
    if (n == 1):
        return 0
    elif (n < 4):
        return 1
    elif (n % 2 == 0):
        return 0
    elif (n < 9):
        return 1
    elif (n % 3 == 0):
        return 0
    else:
        r = int(n**0.5)
        f = 5
        while (f <= r):
            if (n % f == 0):
                return 0
            if (n % (f + 2) == 0):
                return 0
            f += 6
        return 1
        
    
n = int(sys.stdin.next().strip())
candidate = 1
count  = 1
while (count < n):
    candidate += 2
    if (isprime(candidate)):
        count += 1
print candidate

