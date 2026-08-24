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

    int maxval=size[0], minval=size[0];
    int maxind=1, minind=1;
    for(int i=0; i<rows; i++) {
        if (maxval<size[i]) {
            maxval=size[i];
            maxind=i+1;
        }
        if (minval>size[i]) {
            minval=size[i];
            minind=i+1;
        }
    }

    cout << "Row having most elements: " << maxind << endl;
    cout << "Row having fewest elements: " << minind << endl; 

    for (int i=0; i<rows; i++) {
        delete[] array[i];
    }
    delete[] array;
    delete[] size;
}