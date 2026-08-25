#include<iostream>
using namespace std;

class SafeMatrix {
    int** matrix;
    int rows;
    int cols;

    public:
        SafeMatrix(int r, int c) {
            rows = r;
            matrix = new int*[rows];
            cols = c;
            for(int i=0; i<rows; i++) {
                matrix[i] = new int[cols];
            }
        }

        void set(int r, int c, int val) {
            if(r>=0 && r<rows && c>=0 && c<cols) {
                matrix[r][c] = val;
            }
            else {
                cout << "Boundary Error" << endl;
            }
        }

        int get(int r, int c) {
            if(r>=0 && r<rows && c>=0 && c<cols) {
                return matrix[r][c];
            }
            else {
                cout << "Boundary Error" << endl;
                return -1;
            }
        }

        void print() {
            for(int i=0; i<rows; i++) {
                for(int j=0; j<cols; j++) {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
        }

        ~SafeMatrix() {
            for(int i=0; i<rows; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
            matrix = nullptr;
        }
};

int main () {
    SafeMatrix m(4, 4);
    m.set(0, 0, 81);
    m.set(0, 1, 15);
    m.set(0, 2, 37);
    m.set(0, 3, 87);
    m.set(1, 0, 89);
    m.set(1, 1, 23);
    m.set(1, 2, 35);
    m.set(1, 3, 66);
    m.set(2, 0, 63);
    m.set(2, 1, 24);
    m.set(2, 2, 75);
    m.set(2, 3, 32);
    m.set(3, 0, 77);
    m.set(3, 1, 14);
    m.set(3, 2, 86);
    m.set(3, 3, 88);

    cout << "Printing matrix:" << endl;
    m.print();
    int val;
    cout << "Accesing invalid indices: " << endl;

    cout << "Accessing -1 row's 10th column: ";
    val = m.get(-1, 10);
    if (val!=-1) cout << val << endl;

    cout << "Accesing 4th row's 4th column: ";
    val = m.get(4, 4);
    if (val!=-1) cout << val << endl;

    cout << "Accesing 2nd row's 5th column: ";
    val = m.get(2, 5);
    if (val!=-1) cout << val << endl;
}