#include <iostream>
#include <fstream>
#include "film.h"
#include "box.h"
#include "sorter.h"
#include<ctime>
#include<cstdio>


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

float mediana(Box A,int size){
    if(size%2==0) return (A.get_rate((size/2)+1)+A.get_rate((size/2)+2))/2;
    if(size%2==1) return A.get_rate(size/2);
}

float avg(Box A, int size){
    float all=0;
    for (int i = 0; i < size; i++) all+=A.get_rate(i);
    return all/size;

}

/*void save(Box A,int size,fstream &file){
    file.open("wynik.txt",ios::out|ios::trunc);
    for (int i = 0; i < size; i++) {
        file<< A.get_number(i) << " ";
        file << A.get_title(i) << " ";
        file << A.get_rate(i) << " ";
        file << endl;
    }
    file.close();

}*/

int main() {
    //czas byl mierzony poprzez zakomentowywowanie i odkomentowywanie konkretnych linijek kodu oraz przez zmiany nazw obiektow
    fstream file;
    Sorter sorting;

    //Box tenT(10000);
    //Box oneH(100000);
    //Box fiveH(500000);
    //Box all;//962903

    //clock_t start=clock();
    //tenT.download(file,10000);
    //oneH.download(file,100000);
    //fiveH.download(file,500000);
    //nineH.download(file,962903);
    //all.download(file);
    /*clock_t end=clock();
    double time=double(end-start)/CLOCKS_PER_SEC;
    cout<<"time: "<<time*1000<<"ms"<<endl;*/

    //clock_t start=clock();
    //sorting.BucketSort(tenT,1.0,10.0); cout<<"Bucket sort:"<<endl;
    //sorting.MergeSort(tenT,0,tenT.get_size()-1);cout<<"Merge sort:"<<endl;
    //sorting.QuickSort(tenT,0,tenT.get_size()-1);cout<<"Quick sort:"<<endl;
    //clock_t end=clock();
    //double time=double(end-start)/CLOCKS_PER_SEC;
    //cout<<"Rozmiar obiektu:"<<tenT.get_size()<<endl<<"time: "<<time*1000<<"ms"<<endl;
    //cout<<"Avg: "<<avg(tenT,tenT.get_size())<<endl;

    int test_size=15;
    Box test1(test_size);
    Box test2(test_size);
    Box test3(test_size);
    test1.download(file,test_size);
    test3=test2=test1;
    cout<<"Tablica przed posortowaniem:"<<endl;
    printArray(test1,test_size);
    sorting.QuickSort(test1,0,test1.get_size()-1);
    sorting.BucketSort(test2,1.0,10.0);
    sorting.MergeSort(test3,0,test3.get_size()-1);
    cout<<"Qucksort:"<<endl;
    printArray(test1,test_size);
    cout<<"Bucketsort:"<<endl;
    printArray(test2,test_size);
    cout<<"Mergesort:"<<endl;
    printArray(test3,test_size);
    return 0;
}
