#include "sorter.h"
#include "box.h"
#include "film.h"

void Sorter::QuickSort(Box &box, int start, int end) {
    int i=start;
    int j=end;

    int center=box.get_rate((i+j)/2);//srodek elementow
    do
    {
        while(box.get_rate(i)<center) i++;//szukamy elementu wiekszego niz srodek w pierwszej czesci
        while(box.get_rate(j)>center) j--;//szukamy elementu mniejszego niz srodek w drugiej czesci
        if(i<=j)
        {
           box.swap_box(i,j);//zamiana elementow
           i++;
           j--;
        }
    }
    while(i<=j);
    if(j>start) QuickSort(box,start,j);//podzial na mniejsze tablice
    if(i<end) QuickSort(box,i,end);
}

void Sorter::Merge(Box &box, int start, int center, int end) {
    int l_size=center-start+1;
    int r_size=end-center;
    film*left=new film[l_size];
    film*right=new film[r_size];
    for(int i=0;i<l_size;i++) left[i]=box.get(start+i);
    for(int i=0;i<r_size;i++) right[i]=box.get(center+1+i);
    int i=0;
    int j=0;
    int x=start;
    while(i<l_size and j<r_size){
        if(left[i].rate<=right[j].rate){
            box.set(x,left[i]);
            x++;
            i++;
        }
        else{
            box.set(x,right[j]);
            x++;
            j++;
        }
    }
    while(i<l_size){
        box.set(x,left[i]);
        x++;
        i++;
    }
    while(i<r_size){
        box.set(x,right[j]);
        x++;
        j++;
    }
    delete[] left;
    delete[] right;
}

void Sorter::MergeSort(Box &box, int start, int end) {
    if(start>=end) return;
    int center=start+(end-start)/2;
    MergeSort(box,start,center);
    MergeSort(box,center+1,end);
    Merge(box,start,center,end);
}

void Sorter::BucketSort(Box &box, float min, float max) {
    int q_buckets = max - min + 1;//ilosc kubelkow
    Box *buckets = new Box[q_buckets];
    for (int i = 0; i < box.get_size(); i++) {
        int index=static_cast<int>(box.get_rate(i) - min);
        if(buckets[index].get_size() >= buckets[index].get_capacity()) buckets[index].upsize();
        buckets[index].set(buckets[index].get_size(), box.get(i));
        buckets[index].size_plus();
    }
    int index=0;
    for(int i=0;i<q_buckets;i++){
        for(int j=0;j<buckets[i].get_size();j++) {
            box.set(index,buckets[i].get(j));
            index++;
        }
    }
    delete[] buckets;
}