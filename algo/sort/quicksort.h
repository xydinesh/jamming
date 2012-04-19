#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_
#include "sortalgo.h"

class QuickSort : public SortAlgorithms {
  public:
    int sortArray();
    QuickSort();
    QuickSort(int a);
    ~QuickSort();

  private:
    int partition (int p, int q);
    void swap (int i, int j);
    void quicksort (int p, int q);
        
};
#endif
