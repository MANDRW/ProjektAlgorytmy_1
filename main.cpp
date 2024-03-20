#include <iostream>
#include <fstream>
#include "film.h"
#include "box.h"
#include "sorter.h"

using namespace std;

void printArray(Box A, int size)
{
    for (int i = 0; i < size; i++) {
        cout << A.get_number(i) << " ";
        cout << A.get_title(i) << " ";
        cout << A.get_rate(i) << " ";
        cout << endl;
    }
    cout << endl;
}

int main() {
    fstream file;

    Box tenT(10);
    Box oneH(100000);
    Box fiveH(500000);
    Box milion(1000000);
    Box all;

    tenT.download(file,10000);
    oneH.download(file,100000);
    fiveH.download(file,500000);
    milion.download(file,1000000);
    all.download(file);

    Sorter sorting;
    //printArray(tenT,1000);
    sorting.BucketSort(all,1.0,10.0);
    //sorting.MergeSort(all,0,all.get_size()-1);
    //sorting.QuickSort(all,0,all.get_size()-1);




    printArray(all,962903);
    //cout<<tenT.get_capacity()<<endl;
    //printArray(oneH,10);
    //cout<<oneH.get_capacity()<<endl;
    //printArray(fiveH,5000);
    //cout<<fiveH.get_capacity()<<endl;
    /*printArray(milion,10);
    cout<<milion.get_capacity()<<endl;
    printArray(all,10);
    cout<<all.get_capacity()<<endl;
    */
    return 0;
}
