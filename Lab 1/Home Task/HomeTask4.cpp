/*The main issue is the dynamically allocated data array. Since the class doesn't define it's own copy constructor and uses the compiler generated copy constructor, the copy constructed is a shallow copy, which means that b1.data and b2.data point to the same allocated memory. Therefore, when b1.setValue(1, 20) is called, it modifies the shared array, so the change is visible through both b1 and b2. Also, when the objects are destroyed, both destructors call delete[] on the same memory, causing double deletion (undefined behaviour)*/

/*If display() is called after the setValue calls, the corruption is already visible. Both b1 and b2 will display "10 20 0 0 0" because they share the same array. */


#include<iostream>
using namespace std;

class Buffer {
    private:
        int* data;
        int length;
    public:
        Buffer(int len) {
            length = len;
            data = new int[length];
            for (int i = 0; i < length; i++) data[i] = 0;
            }

        void setValue(int index, int value) {
            data[index] = value;
        }

        //deep-copy copy constructor
        Buffer(const Buffer& other) {
            length = other.length;
            data = new int[length];

            for (int i = 0; i < length; i++) {
                data[i] = other.data[i];
            }
        }

        //copy assignment operator
        Buffer& operator=(const Buffer& other) {
            if (this == &other) {
                return *this;
            }
            delete[] data;

            length = other.length;
            data = new int[length];

            for (int i = 0; i < length; i++) {
                data[i] = other.data[i];
            }

            return *this;
        }

        void display() const {
            for (int i = 0; i < length; i++)
                cout << data[i] << " ";
            cout << endl;
        }

        ~Buffer() {
            delete[] data;
        }
};
int main() {
    Buffer b1(5);
    b1.setValue(0, 10);
    Buffer b2 = b1; 
    b2.setValue(1, 20);
    b1.display();
    b2.display();
    return 0; 
}