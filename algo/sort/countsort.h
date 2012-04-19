#ifndef __COUNTSORT_H__
#define __COUNTSORT_H__
#include "sortalgo.h"

class CountSort : public SortAlgorithms {
  public:
    CountSort();
    CountSort(int i);
    ~CountSort();
    int sortArray();
};
#endif  /* __COUNTSORT_H__ */
