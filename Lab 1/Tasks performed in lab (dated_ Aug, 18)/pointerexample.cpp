#include<iostream>
using namespace std;

class Student {
    public:
        int* arr;
        int size;

        Student(int s) {
            size = s;
            arr = new int[s];
        }
        void input() {
            for (int i=0;i<size;i++) {
                cout << "Enter subject " << i+1 << " marks: ";
                cin >> *(arr+i);
            }
        }
        float avg() {
            float sum = 0;
            for(int i=0; i<size; i++) {
              sum += arr[i];
            }
            float avg = sum/float(size);
            return avg;
        }
        ~Student() {
            delete[] arr;
        }
};

int main () {
    int n;
    cout << "Enter the number of subjects: ";
    cin >> n;
    Student s(n);
    s.input();
    cout << "The average is: " << s.avg() << endl;
}