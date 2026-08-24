#include <iostream>
using namespace std;

class SafeArray {
    int size;
    int* array;

    public:
        SafeArray(int s) {
            size = s;
            array = new int [size];
        }

        void set(int pos, int val) {
            if (pos>=0 && pos<=size-1) {
                array[pos] = val;
            } 
            else cout << "Boundary Error" << endl;
        }

        int get(int pos) {
            if (pos>=0 && pos<=size-1) {
                return array[pos];
            }
            else {
                cout << "Boundary Error" << endl;
                return -1;
            }
        }

        void display() {
            for(int i=0; i<size; i++) cout << array[i] << " ";
            cout << endl;
        }

        ~SafeArray() {
            delete[] array;
        }
};

int main () {
    SafeArray arr(5);
    arr.set(0, 3);
    arr.set(1, 4);
    arr.set(2, 5);
    arr.set(3, 7);
    arr.set(4, 6);

    cout << "Displaying the array after writing it: " << endl;
    arr.display();

    cout << "Getting individual elements: " << endl;
    cout << "Element 3: " << arr.get(3) << endl;
    cout << "Element 4: " << arr.get(4) << endl;

    // reading at wrong position
    cout << "Getting 10th element: ";
    int element = arr.get(10);
    if (element!=-1) cout << element << endl;

    //writing from wrong position
    cout << "Writing -1 element: ";
    arr.set(-1, 10);
}