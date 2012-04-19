#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, const char **argv)
{
    char *x;
    int i;
    int len;
    int value;
    int mflag = 0;

    if (argc < 2)
    {
        fprintf (stderr, "usage: %s number\n", argv[0]);
        exit (0);
    }

    x = (char *)argv[1];
    value = 0;
    
    len = strlen(x);
    for (i = 0; i < len; i++)
    {
        if (!mflag && (x[0] == '-'))
        {
            mflag = 1;
            continue;
        }

        if (x[i] >= '0' && x[i] <= '9')
            value = (value << 3) + (value << 1) + (x[i] - '0');
    }
    
    if (mflag)
        value *= -1;
    
    printf ("%d\n", value);

    return 0;
}
