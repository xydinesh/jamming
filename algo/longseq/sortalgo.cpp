#include "sortalgo.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <algorithm>

int SortAlgorithms::processInput(int val)
{
    int i = 0;
    srand(time(NULL));
    for (i = 0; i < val; i++)
    {
        this->elements.push_back(rand()% this->randvalue);
        this->initElements.push_back(this->elements[i]);
    }
    this->nelements = val;
    return 0;
}

void SortAlgorithms::verifyOutput()
{
    int i;
    std::vector<int> tmpVec(initElements.begin(), initElements.end());
    sort(tmpVec.begin(), tmpVec.end());
    for (i = 0; i < nelements; i++)
    {        
        //printf ("%d:%d\n", tmpVec[i], elements[i]);
        assert(tmpVec[i] == elements[i]);
    }
}

void SortAlgorithms::printInput()
{
    int i = 0;
    for (i = 0; i < this->nelements; i++)
    {
        printf ("%d ", elements[i]);
    }
    printf ("\n");
}


int SortAlgorithms::sortArray()
{
    return 0;
}


SortAlgorithms::~SortAlgorithms()
{
}

SortAlgorithms::SortAlgorithms ()
{
    this->randvalue = 10;
}


SortAlgorithms::SortAlgorithms (int i)
{
    this->randvalue = i;
}


SortAlgorithms&
SortAlgorithms::operator=(const SortAlgorithms &sa)
{
    elements = sa.elements;
    initElements = sa.initElements;
    nelements = sa.nelements;
    randvalue = sa.randvalue;
    return *this;
}


