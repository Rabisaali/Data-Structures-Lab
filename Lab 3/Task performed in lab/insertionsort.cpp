#include<iostream>
using namespace std;

void InsertionSort(int arr[], int n) {
    for(int i=1; i<n; i++) {
        int key = arr[i];
        int j=i-1;

        while(j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

int main () {
    int n;
    cout << "Enter number of elemnts of array: ";
    cin >> n;
    int* arr = new int[n];

    for(int i=0; i<n; i++) {
        cout << "Enter element: " << i+1 << ": ";
        cin >> arr[i];
    }

    InsertionSort(arr, n);

    cout << "Sorted Array is: " << "\n";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
}