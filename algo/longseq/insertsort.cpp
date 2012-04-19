#include "insertsort.h"

int InsertSort::sortArray()
{
    int i, j, k;
    for (j = 1; j < nelements; j++)
    {
        k = elements[j];
        i = j - 1;
        while (i >= 0 && (elements[i] > k))
        {
            elements[i+1] = elements[i];
            i--;
        }

        elements[i+1] = k;
    }

    return 0;
}

InsertSort::~InsertSort()
{
}

InsertSort::InsertSort()
{
}

InsertSort::InsertSort(int i) : SortAlgorithms(i)
{
}
