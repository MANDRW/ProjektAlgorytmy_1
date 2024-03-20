#ifndef PIAA_1_BOX_H
#define PIAA_1_BOX_H
#include"film.h"
#include<string>
#include<fstream>

using namespace std;

class Box{
private:
    film*box=NULL;
    int size;
    int capacity;
public:
    Box();
    Box(int s);
    void upsize();
    void download(fstream &file,int quantity=0);
    void size_plus();
    int get_size();
    int get_capacity();
    int get_number(int i);
    string get_title(int i);
    float get_rate(int i);
    film get(int i);
    void set_number(int i,int n);
    void set_title(int i,string t);
    void set_rate(int i,float r);
    void set(int i,film temp);
    void swap_box(int i,int j);
    ~Box();
};

#endif
