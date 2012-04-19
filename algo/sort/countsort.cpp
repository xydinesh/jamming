#include "countsort.h"

CountSort::CountSort()
{
}
 
CountSort::CountSort(int i) : SortAlgorithms (i)
{
}

CountSort::~CountSort()
{
}
 

int CountSort::sortArray()
{
    std::vector<int> count_vec(randvalue, 0);
    std::vector<int> sorted_vec(nelements, 0);
    int i = 0;

    for (i = 0; i < nelements; i++)
    {
        count_vec[elements[i]]++;
    }

    for (i = 1; i < randvalue; i++)
    {
        count_vec[i] += count_vec[i-1];
    }


    for (i = (nelements - 1); i >= 0; i--)
    {
        sorted_vec[count_vec[elements[i]] - 1] = elements[i];
        count_vec[elements[i]]--;
    }
    
    elements = sorted_vec;
    return 0;
}
