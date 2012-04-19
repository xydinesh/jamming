#include "quicksort.h"

int QuickSort::sortArray ()
{
    quicksort (0, nelements - 1);
    return 0;
}

void QuickSort::quicksort(int p, int q)
{
    int r = 0;
    if (p < q)
    {
        r = partition (p, q);
        quicksort (p, r - 1);
        quicksort (r + 1, q);
    }

}

int QuickSort::partition (int p, int q)
{
    int pivot = elements[p];
    int i , j;
    i = p;
    for (j = p + 1; j <= q; j++)
    {
        if (elements[j] <= pivot)
        {
            i++;
            swap(j, i);
        }
    }
    swap(p, i);
    return i;
}

void QuickSort::swap (int i, int j)
{
    if (elements[i] == elements[j])
        return;

    elements[i] ^= elements[j];
    elements[j] ^= elements[i];
    elements[i] ^= elements[j];
}

QuickSort::QuickSort () {}

QuickSort::~QuickSort() {}

QuickSort::QuickSort (int a) : SortAlgorithms (a) {}


