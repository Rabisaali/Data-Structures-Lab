#include<iostream>
#include<exception>
using namespace std;

class Matrix {
    int rows, cols;
    int** data;

    public:
        Matrix(int r, int c) {
            cout << "Calling Parametrized Constructor" << endl;
            rows = r;
            cols = c;

            data = new int*[rows];

            for(int i=0; i<rows; i++) {
                data[i] = new int[cols];

                for(int j=0; j<cols; j++) {
                    data[i][j] = 0;
                }
            }
        }

        Matrix(const Matrix& other) {

            cout << "Calling Copy Constructor" << endl;
            rows = other.rows;
            cols = other.cols;

            data = new int*[rows];

            for (int i=0; i<rows; i++) {
                data[i] = new int[cols];

                for(int j=0; j<cols; j++) {
                    data[i][j]=other.data[i][j];
                }
            }
        }

        Matrix& operator= (const Matrix& other) {
            cout << "Calling Overloaded Assignment Operator" << endl;

            for (int i = 0; i < rows; i++) {
                delete[] data[i];
            }
            delete[] data;

            rows = other.rows;
            cols = other.cols;

            data = new int*[rows];

            for (int i=0; i<rows; i++) {
                data[i] = new int[cols];

                for(int j=0; j<cols; j++) {
                    data[i][j]=other.data[i][j];
                }
            }
            return *this;
        }

        void set (int r, int c, int value) {
            if (r>=0 && r<rows && c>=0 && c<cols) {
                data[r][c] = value;
            }
            else {
                throw "Error: Out of bounds!";
            }
        }

        int get (int r, int c) const {
            if (r>=0 && r<rows && c>=0 && c<cols) {
                return data[r][c];
            }
            else {
                throw "Error: Out of bounds!";
            }
        }

        void display() {
            for(int i=0; i<rows; i++) {
                for(int j=0; j<cols; j++) {
                    cout << data[i][j] << " ";
                }
                cout << endl;
            }
        }

        int get_rows() const {
            return rows;
        }

        int get_cols() const {
            return cols;
        }

        Matrix operator+ (const Matrix& other) const {
            if (rows==other.get_rows() && cols==other.get_cols()) {
                Matrix m(rows, cols);

                for(int i=0; i<rows; i++) {
                    for(int j=0; j<cols; j++) {
                        m.data[i][j] = data[i][j] + other.data[i][j];
                    }
                }
                return m;
            }
            else {
                throw "Error: Not same sized!";
            }
        }

        ~Matrix() {
            cout << "Calling Destructor" << endl;
            for(int i=0; i<rows; i++) {
                delete[] data[i];
            }
            delete[] data;
        }
};

int main () {
    try {
        Matrix m1(2,2);
        Matrix m2(2,2);

        m1.set(0, 0, 1);
        m1.set(0, 1, 3);
        m1.set(1, 0, 4);
        m1.set(1, 1, 3);

        m2.set(0, 0, 4);
        m2.set(0, 1, 4);
        m2.set(1, 0, 5);
        m2.set(1, 1, 6);

        cout << "Matrix 1:" << endl;
        m1.display();
        cout << endl;

        cout << "Matrix 2: " << endl;
        m2.display();
        cout << endl;

        Matrix sum = m1+m2;
        cout << "After summing: " << endl;
        sum.display();
        cout << endl;

        Matrix m3(m1);

        Matrix m4(2,2);
        m4 = m2;

        cout << "Before changing: " << endl;
        cout << "Matrix 1:" << endl;
        m1.display();

        cout << "Matrix 2:" << endl;
        m2.display();

        cout << "Matrix 3:" << endl;
        m3.display();

        cout << "Matrix 4:" << endl;
        m4.display();

        m3.set(1, 0, 9);
        m4.set(0, 1, 0);

        cout << "After changing: " << endl;
        cout << "Matrix 1:" << endl;
        m1.display();

        cout << "Matrix 2:" << endl;
        m2.display();

        cout << "Matrix 3:" << endl;
        m3.display();

        cout << "Matrix 4:" << endl;
        m4.display();
    }
    catch (const char* message) {
        cout << message << endl;
    }
}