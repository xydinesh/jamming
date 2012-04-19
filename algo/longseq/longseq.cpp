#include "longseq.h"
#include <vector>
#include <algorithm>

LongSeq::LongSeq (){}

LongSeq::LongSeq (int i) : SortAlgorithms (i) {}

LongSeq::~LongSeq(){}

int LongSeq::sortArray() { return 0;}

void LongSeq::findLongSeq()
{
    std::vector<int> seqlen(nelements, 0);
    int i = 0;
    int max;
    int index;
    seqlen[0] = 0;
    max = seqlen[0];
    index = 0;
    for (i = 1; i < nelements; i++)
    {
        if (elements[i-1] < elements[i])
        {
            seqlen[i] = seqlen[i-1] + 1;
            if (seqlen[i] > max)
            {
                max = seqlen[i];
                index = i - max;
            }
        }
        else
            seqlen[i] = 0;
    }
    printf ("length of longest sequence:%d index: %d\n", max, index);
}
