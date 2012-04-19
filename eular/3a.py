#!/usr/bin/python
import sys

def primefactor(n):
    limit = int(n**0.5)
    factors = []
    candidate = 3;

    while(n % 2 == 0):
        if not (len(factors) > 0):
            factors.append(2)
        n /= 2

    while(candidate <= limit):
        while(n % candidate == 0):
            if (len(factors) > 0):
                if (factors[len(factors) - 1] != candidate):
                    factors.append(candidate)
            else:
                factors.append(candidate)
            n /= candidate
        candidate += 2

    factors.append(n)
    print max(factors), factors

n = int(sys.stdin.next().strip())
primefactor(n)


