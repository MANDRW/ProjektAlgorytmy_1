#include"box.h"
#include"film.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


Box::Box():box(new film[4]),size(0),capacity(4){}
Box::Box(int s):box(new film[s]),size(0),capacity(s){}

void Box::upsize() {
    film*temp=new film[capacity*2];
    for(int i=0;i<size;i++) temp[i]=box[i];
    delete[] box;
    box=temp;
    capacity*=2;


}

void Box::download(fstream &file,int quantity) {
    film work;
    int number;
    float rate;
    string tempn,tempt,tempr;
    file.open("projekt2_dane.csv",ios::in);
    for(int i=0;file.eof()!=1;i++){
        if(i==0){
            getline(file,tempt);
            continue;
        }
        if(quantity!=0)
            if(i>quantity) break;
        if(quantity==0 and size>=capacity) upsize();
        getline(file,tempn,',');
        getline(file,tempt);
        tempr=tempt.substr(tempt.length()-4);
        if(tempr[0]==',') {
            tempr=tempr.substr(1,3);
            tempt.erase(tempt.length()-4);
        }
        else tempt.erase(tempt.length()-5);
        if(tempr[tempr.length()-2]!='.')
        {
            i--;
            continue;
        }
        number=stoi(tempn);
        rate=stof(tempr);
        work.number=number;
        work.title=tempt;
        work.rate=rate;
        box[i-1]=work;
        size++;
    }
    file.close();

}

void Box::size_plus() {
    size++;
}

int Box::get_number(int i) {
    return box[i].number;
}
string Box::get_title(int i) {
    return box[i].title;
}
float Box::get_rate(int i) {
    return box[i].rate;
}
film Box::get(int i) {
    return box[i];
}

void Box::set_number(int i,int n) {
    box[i].number=n;
}
void Box::set_title(int i, string t) {
    box[i].title=t;
}
void Box::set_rate(int i,float r) {
    box[i].rate=r;
}
int Box::get_size() {
    return size;
}
int Box::get_capacity() {
    return capacity;
}
void Box::set(int i, film temp) {
    box[i]=temp;
}
void Box::swap_box(int i, int j) {
    swap(box[i],box[j]);
}
Box::~Box(){}