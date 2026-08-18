#include<bits/stdc++.h>
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
        Student(const Student& s1) {
            size = s1.size;
            arr = new int[size];
            for(int i=0; i<size; i++) {
                *(arr+i) = *(s1.arr + i);
            }
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
    
    Student s2 = s;
    s2.arr[3]=45;
    cout << "The average is (s2): " << fixed << setprecision(6) << s2.avg() << endl;
    cout << "The average is (s1): " << fixed << setprecision(6) << s.avg() << endl;
}