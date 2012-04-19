#ifndef __SORT_ALGO_H__
#define __SORT_ALGO_H__

#include <vector>
#include <cstdio>
#include <cstdlib>
#include <ctime>

class SortAlgorithms{
  public:
    int processInput(int val);
    void printInput();
    void verifyOutput();

    virtual int sortArray() = 0;

    // operators
    SortAlgorithms& operator=(const SortAlgorithms& sa);

  protected:
    std::vector<int> elements;
    std::vector<int> initElements;
    int nelements;
    int randvalue;

    // constructors and destructors
    SortAlgorithms();
    SortAlgorithms(int size);
    virtual ~SortAlgorithms();

};
#endif
