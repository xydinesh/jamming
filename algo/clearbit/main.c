#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, const char **argv)
{
    int val;
    int pos;
    int mask = 0;
    if (argc < 3)
    {
        fprintf (stderr, "usage: %s number position\n", argv[0]);
        exit (0);
    }

    val = atoi(argv[1]);
    pos = atoi(argv[2]);
    printf ("%016x\n", val);
    mask = 1 << pos;
    mask = ~mask;
    val &= mask;
    printf ("%016x\n", val);

    return 0;
}
