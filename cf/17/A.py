#!/usr/bin/python
import sys
prime = []

def getprime(n):
    i = 2;
    while (i <= n):
        j = i - 1;
        while (j > 0):
            if ((i % j) == 0):
                break;
            j -= 1
        if (j == 1):
            prime.append(i)
        i += 1

(n,k) = map(int, sys.stdin.next().strip().split (" "))
getprime (n)
count = 0
for i in xrange(len(prime) - 1):
    su = prime[i] + prime[i + 1] + 1
    for j in xrange(i+1, len(prime)):
        if (su == prime[j]):
            count += 1

if (count >= k):
    print "YES"
else:
    print "NO"
    
    

    
    

