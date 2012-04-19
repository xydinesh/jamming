#include <cstdio>
#include <cstdlib>
#include "sortalgo.h"
#include "longseq.h"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf (stderr, "usage: ./sortalgo #of elements\n");
        exit (-1);
    }

    LongSeq ls(100);
    ls.processInput(atoi(argv[1]));
    ls.printInput();
    ls.findLongSeq();
    return 0;
}
