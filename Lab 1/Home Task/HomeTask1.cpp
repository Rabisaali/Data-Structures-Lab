#include<iostream>
#include<cstring>
using namespace std;

class DynamicString {
    char* data;

    public:
        DynamicString() {
            cout << "Calling Default Constructor" << endl;
            data = new char[1];
            data[0] = '\0';
        }

        DynamicString(const char* text) {
            cout << "Calling Parametrized Constructor" << endl;
            data = new char[strlen(text)+1];
            strcpy(data, text);
        }

        DynamicString(const DynamicString& other) {
            cout << "Calling Copy Constructor" << endl;
            data = new char[strlen(other.data)+1];
            strcpy(data, other.data);
        }

        DynamicString& operator= (const DynamicString& other) {
            cout << "Calling Overloaded Assignment Operator" << endl;
            if (this == &other) {
                return *this;
            } 
            delete[] data;
            data = new char[strlen(other.data)+1];
            strcpy(data, other.data);
            return *this;
        }

        int length() const {
            return strlen(data);
        }

        void print() const {
            cout << data << "\n";
        }

        void setChar(int index, char c) {
            if (index>=0 && index<length()) {
                *(data+index) = c;
            }
        }

        ~DynamicString() {
            cout << "Calling Destructor" << endl;
            delete[] data;
        }
};

int main () {
    DynamicString d1("hello, world :D");
    DynamicString d2 = d1;
    DynamicString d3;
    d3 = d1;

    cout << "Before Modification: " << endl;

    cout << "String 1: ";
    d1.print();
    cout << endl;

    cout << "String 2: ";
    d2.print();
    cout << endl;

    cout << "String 3: ";
    d3.print();
    cout << endl;

    d1.setChar(14, '(');

    cout << "After Modification: " << endl;

    cout << "String 1: ";
    d1.print();
    cout << endl;

    cout << "String 2: ";
    d2.print();
    cout << endl;

    cout << "String 3: ";
    d3.print();
    cout << endl;
}