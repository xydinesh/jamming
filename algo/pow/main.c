#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

unsigned long long power_function(int x, int n);

int main (int argc, const char **argv)
{
    int x = 0;
    int n = 0;
    if (argc < 3)
    {
        fprintf (stderr, "./usage: %s x n \n Compute x^n", argv[0]);
        exit (-1);
    }
    x = atoi(argv[1]);
    n = atoi(argv[2]);

    printf ("%llu\n", power_function(x, n));
    
    return 0;
}

unsigned long long power_function(int x, int n)
{
    unsigned long long v = 0;
    unsigned long long k = 0;

    if (n == 0)
        return (unsigned long long) 1;
    
    if (n == 1)
        return (unsigned long long)x;
    
    if (n%2)
    {
        k = power_function(x, (n - 1)/2);
        v = k*k*x;
    }
    else
    {
        k = power_function(x, n/2);
        v = k*k;
    }
    
    return v;
}
