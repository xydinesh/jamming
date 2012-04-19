#ifndef __LONGSEQ_H_
#define __LONGSEQ_H_
#include "sortalgo.h"

class LongSeq : public SortAlgorithms {
  public:
    LongSeq();
    ~LongSeq();
    int sortArray();
    LongSeq(int i);
    void findLongSeq();
};
#endif  /* __LONGSEQ_H_ */
