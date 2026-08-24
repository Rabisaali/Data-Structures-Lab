#include <iostream>
using namespace std;

int main () {
    int rows;
    cout << "Enter number of rows: ";
    cin >> rows;
    int** array = new int* [rows];

    //size array to store the size of each row
    int* size = new int[rows];

    for (int i=0; i<rows; i++) {
        cout << "Enter size of row " << i+1 << ": ";
        cin >> size[i];
        array[i] = new int[size[i]];
    }

    for(int i=0; i<rows; i++) {
        cout << "Enter " << size[i] << " elements for row " << i+1 << ": ";
        for(int j=0; j<size[i]; j++) {
            cin >> array[i][j];
        } 
    }
    cout << endl;
    cout << "Jagged Array Elements: " << endl;

    for(int i=0; i<rows; i++) {
        cout << "Row " << i+1 << ": ";
        for(int j=0; j<size[i]; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    for(int i=0; i<rows; i++) {
        cout << "Sum of row " << i+1 << ": ";
        int sum=0;
        for(int j=0; j<size[i]; j++) {
            sum += array[i][j];
        }
        cout << sum << endl;
        cout << "Average of row " << i+1 << ": " << double(sum)/double(size[i]) << endl; 
    }

    cout << "Row having maximum "

    for (int i=0; i<rows; i++) {
        delete[] array[i];
    }
    delete[] array;
}