#include "mergesort.h"

int MergeSort::sortArray ()
{
    std::vector<int> sortedArray;
    sortRec(elements, &sortedArray);
    for (int i = 0; i < (int)sortedArray.size(); i++)
    {
        elements[i] = sortedArray[i];
    }
    return 0;
}

void MergeSort::sortRec (std::vector<int> partArray, std::vector<int> *mv)
{
    if ((int)partArray.size() == 1)
    {
        (*mv).push_back(partArray[0]);
        return;
    }

    int n = ((int)partArray.size())/2;

    std::vector<int> fh;
    std::vector<int> sh;
    std::vector<int> fhs;
    std::vector<int> shs;

    fh.insert(fh.end(), partArray.begin(), partArray.begin() + n);
    sh.insert(sh.end(), partArray.begin()+n, partArray.end());
    
    sortRec(fh, &fhs);
    sortRec(sh, &shs);

    // Below this point is merge operation.
    while ((!fhs.empty()) and (!shs.empty()))
    {
        if (fhs.front() < shs.front())
        {
            (*mv).push_back(fhs.front());
            fhs.erase(fhs.begin());
        }
        else
        {
            (*mv).push_back(shs.front());
            shs.erase(shs.begin());
        }
    }

    if (!fhs.empty())
    {
        (*mv).insert((*mv).end(), fhs.begin(), fhs.end());
    }

    if (!shs.empty())
    {
        (*mv).insert((*mv).end(), shs.begin(), shs.end());
    }
}

MergeSort::MergeSort()
{

}

MergeSort::~MergeSort()
{
}

MergeSort::MergeSort(int i) : SortAlgorithms(i)
{

}
