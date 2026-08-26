#include<iostream>
using namespace std;

int main () {
    int rows1, cols1, rows2, cols2;

    cout << "Enter the number of rows of matrix A: ";
    cin >> rows1;

    cout << "Enter the number of cols of matrix A: ";
    cin >> cols1;

    int** matrixA = new int* [rows1];
    for(int i=0; i<rows1; i++) matrixA[i] = new int[cols1];

    cout << "Enter the number of rows of matrix B: ";
    cin >> rows2;

    cout << "Enter the number of cols of matrix B: ";
    cin >> cols2;

    int** matrixB = new int* [rows2];
    for(int i=0; i<rows2; i++) matrixB[i] = new int[cols2];

    int choice=-1;

    do {
        cout << "For Addition enter 1\nFor Multiplication enter 2\nTo exit enter 3\n";
        cout << "Choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                if (rows1 == rows2 && cols1 == cols2) {

                    int** result = new int* [rows1];
                    for(int i=0; i<rows1; i++) {
                        result[i] = new int[cols1];
                    }

                    for(int i=0; i<rows1; i++) {
                        for(int j=0; j<cols1; j++) {
                            result[i][j] = matrixA[i][j] + matrixB[i][j];
                        }
                    }

                    cout << "The resultant matrix is: " << endl;
                    for(int i=0; i<rows1; i++) {
                        for (int j=0; j<cols1; j++) {
                            cout << result[i][j] << " ";
                        }
                        cout << endl;
                    }

                    for (int i=0; i<rows1; i++) delete[] result[i];
                    delete[] result;
                    break;
                }
                else {
                    cout << "Error: Invalid index!" << endl;
                    break;
                }

            case 2:
                if (cols1 == rows2) {
                    int** result = new int* [rows1];
                    for(int i=0; i<rows1; i++) {
                        result[i] = new int[cols2];
                    }

                    for(int i=0; i<rows1; i++) {
                        for(int j=0; j<cols2; j++) {
                            result[i][j] = 0;
                            for(int k=0; k<cols1; k++) {
                                result[i][j] += matrixA[i][k]*matrixB[k][j];
                            }
                        }
                    }

                    cout << "The resultant matrix is: " << endl;
                    for(int i=0; i<rows1; i++) {
                        for (int j=0; j<cols2; j++) {
                            cout << result[i][j] << " ";
                        }
                        cout << endl;
                    }

                    for (int i=0; i<rows1; i++) delete[] result[i];
                    delete[] result;

                    break;
                }
                else {
                    cout << "Error: Invalid index!" << endl;
                    break;
                }

        case 3:
            cout << "Exiting program....." << endl;
            break;

        default:
                cout << "Invalid choice" << endl;
        }

    } while(choice != 3);

    for(int i=0; i<rows1; i++) delete[] matrixA[i];
    delete[] matrixA;

    for(int i=0; i<rows2; i++) delete[] matrixB[i];
    delete[] matrixB;

    return 0;
}