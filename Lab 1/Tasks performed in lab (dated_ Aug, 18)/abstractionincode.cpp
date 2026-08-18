#include<iostream>
using namespace std;

class A {
    protected:
        int a;
        virtual void func() = 0;
    public:
        A() {
            a=5;
        }
};

class B: public A {
    public:
        void func() {
            cout << "the value of variable inherited through class A is: " << a << "\n";
        }
};

int main () {
    B obj;
    obj.func();
}