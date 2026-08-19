#include<iostream>

using namespace std;

class DynamicArray {
    int* arr;
    int size;
    int capacity;

    public:
        DynamicArray() {
            cout << "Calling Default Constructor" << endl;
            capacity=2;
            size=0;
            arr = new int[capacity];
        }  

        void pushBack(int value) {
            if(size==capacity) {
                capacity *= 2;
                int* arr_temp = new int[capacity];
                for(int i=0; i<size; i++) {
                    arr_temp[i] = arr[i];
                }
                delete[] arr;
                arr = arr_temp;
            }
            arr[size]=value;
            size++;
        }

        int& operator[](int index) {
            if (index>=0 && index<size) {
                return arr[index];
            }
            else throw "Index out of bounds";
        }

        DynamicArray(const DynamicArray& other) {
            cout << "Calling Copy Constructor" << endl;
            size = other.size;
            capacity = other.capacity;

            arr = new int[capacity];

            for(int i=0; i<size; i++) {
                arr[i] = other.arr[i];
            }
        }

        DynamicArray& operator= (const DynamicArray& other) {
            
            if (this == &other) {
                return *this;
            }
            cout << "Calling Copy Assignment Operator" << endl;
            delete[] arr;
            size = other.size;
            capacity = other.capacity;

            arr = new int[capacity];

            for(int i=0; i<size; i++) {
                arr[i] = other.arr[i];
            }
            return *this;
        }

        void print() const {
            for(int i=0; i<size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        ~DynamicArray() {
            cout << "Calling Destructor" << endl;
            delete[] arr;
        }
};

int main () {
    try {
        DynamicArray vec;
        vec.pushBack(6);
        vec.pushBack(0);
        vec.pushBack(10);
        vec.pushBack(19);
        vec.pushBack(8);
        vec.pushBack(7);

        cout << "Original Vector: ";
        vec.print();
        cout << endl;

        DynamicArray vec2 = vec;

        DynamicArray vec3;
        vec3 = vec;

        cout << "Before Modification:" << endl;
        cout << "Vector 1: " << endl;
        vec.print();
        cout << endl;

        cout << "Vector 2: " << endl;
        vec2.print();
        cout << endl;

        cout << "Vector 3: " << endl;
        vec3.print();
        cout << endl;

        vec2[4] = 19;
        vec2[0] = 15;

        vec3[3] = 16;
        vec3[2] = 14;

        cout << "After Modification:" << endl;
        cout << "Vector 1: " << endl;
        vec.print();
        cout << endl;

        cout << "Vector 2: " << endl;
        vec2.print();
        cout << endl;

        cout << "Vector 3: " << endl;
        vec3.print();
        cout << endl;
    }
    catch (const char* message) {
        cout << message << endl;
    } 
}