#include<iostream>
using namespace std;

int* BubbleSort(int* arr, int n) {
    int count=0;
    for(int i=0; i<n; i++) {
        for (int j=0; j<n-1; j++) {
            if (arr[j]>arr[j+1]) {
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1] = temp;
                count++;
            }
        }
    }
    cout << "Number of swaps required to sort the array are: " << count << "\n";
    return arr;
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

    arr = BubbleSort(arr, n);

    cout << "Sorted Array is: " << "\n";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
}