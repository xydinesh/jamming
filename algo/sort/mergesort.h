#ifndef __MERGE_SORT_H__
#define __MERGE_SORT_H__
#include "sortalgo.h"
#include <vector>

class MergeSort : public SortAlgorithms {
  public:
    MergeSort(int i);
    MergeSort();
    ~MergeSort();
    int sortArray();
  private:
    void sortRec(std::vector<int> partArray, std::vector<int> *mergedVec);
};

#endif
