#ifndef HEADER_H
#define HEADER_H
#include<iostream> 

class Num {
    public:
    int x, y;
    Num(int a, int b) {
        x=a;
        y=b;
    }
    int add () {
        return x+y;
    }
};

#endif