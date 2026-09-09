#include<iostream>
using namespace std;

void SelectionSort(int arr[], int n) {
    int count=0;
    for(int i=0; i<n-1; i++) {
        int min_index=i;

        for(int j=i+1; j<n; j++) {
            if (arr[j]<arr[min_index]) {
                min_index = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
        count++;
    }
    cout << "Number of swaps required to sort the array are: " << count << "\n";
    return;
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

    SelectionSort(arr, n);

    cout << "Sorted Array is: " << "\n";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
}