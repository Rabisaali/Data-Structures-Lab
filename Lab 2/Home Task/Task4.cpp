#include<iostream>
using namespace std;

class DynamicSafeArray {
    int* arr;
    int count;
    int initialCapacity;

    public:
        DynamicSafeArray(int initCap) {
            initialCapacity=initCap;
            count=0;
            arr = new int[initialCapacity];
        }  

        void pushBack(int value) {
            if(count==initialCapacity) {
                initialCapacity *= 2;
                int* arr_temp = new int[initialCapacity];
                for(int i=0; i<count; i++) {
                    arr_temp[i] = arr[i];
                }
                delete[] arr;
                arr = arr_temp;
            }
            arr[count]=value;
            count++;
        }

        void set(int pos, int val) {
            if (pos >= 0 && pos < count) {
                arr[pos] = val;
            }
            else cout << "Boundary Error: Invalid access!" << endl;
        }

        int get(int pos) {
            if (pos >= 0 && pos < count) {
                return arr[pos];
            }
            else {
                cout << "Boundary Error: Invalid access!" << endl;
                return -1;
            }
        }

        bool removeAt(int pos) {
            if (pos >= 0 && pos < count) {
                for(int i=pos; i<count-1; i++) {
                    arr[i] = arr[i+1];
                }
                count--;
                return true;
            }
            else {
                cout << "Boundary Error: Pos is invalid" << endl;
                return false;
            }
        }

        void display() {
            for(int i=0; i<count; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        } 

        ~DynamicSafeArray() {
            delete[] arr;
        }
};

int main () {
    DynamicSafeArray v(2);
    v.pushBack(1);
    v.pushBack(3);
    v.pushBack(6);
    v.pushBack(4);
    v.pushBack(8);
    v.pushBack(9);

    cout << "The array is: ";
    v.display();

    bool val = v.removeAt(3);
    if (val) {
        cout << "Operation of removing element at position 3 successful!" << endl;
    }

    cout << "The array after removal is: ";
    v.display();

    cout << "Trying to get position 9: " << endl;
    int ans = v.get(9);

    if (ans!=-1) cout << "The value at position 9 is: " << ans << "\n";

    cout << "Trying to set 9 at position 10: ";
    v.set(10, 9);

    cout << "The final array is: ";
    v.display();
}