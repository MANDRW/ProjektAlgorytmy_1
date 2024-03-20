#ifndef PIAA_1_SORTER_H
#define PIAA_1_SORTER_H
#include "box.h"
class Sorter{
private:
    void Merge(Box&box,int start,int center,int end);
public:
    void QuickSort(Box&box,int start, int end);
    void MergeSort(Box&box,int start,int end);
    void BucketSort(Box&box,float min,float max);
};
#endif
