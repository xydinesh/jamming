#include <cstdio>
#include <cstdlib>
#include "sortalgo.h"
#include "insertsort.h"
#include "mergesort.h"
#include "quicksort.h"
#include "countsort.h"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf (stderr, "usage: ./sortalgo #of elements\n");
        exit (-1);
    }

    printf ("Insert sort\n");
    InsertSort ins(30);
    InsertSort ic;

    ins.processInput(atoi(argv[1]));
    ins.printInput ();
    ins.sortArray ();

    // copying objects
    ic = ins;
    ic.verifyOutput();
    ic.printInput();

    printf ("Merge sort\n");
    MergeSort ms(40);
    ms.processInput(atoi(argv[1]));
    ms.printInput();
    ms.sortArray();
    ms.verifyOutput();
    ms.printInput();

    printf ("Quick sort\n");
    QuickSort qs(100);
    qs.processInput(atoi(argv[1]));
    qs.printInput();
    qs.sortArray();
    qs.verifyOutput(); 
    qs.printInput ();


    printf ("Count sort\n");
    CountSort cs(1024);
    cs.processInput (atoi(argv[1]));
    cs.printInput();
    cs.sortArray();    
    qs.verifyOutput();                  
    cs.printInput();
    return 0;
}
