#include<iostream>
using namespace std;

void ShellSort(int arr[], int n) {
    int count = 0;
    for(int gap = n/2; gap>0; gap/=2) {
        for(int j=gap; j<n; j++) {
            int temp = arr[j];
            int res = j;

            while(res>=gap && arr[res-gap]>temp) {
                arr[res]= arr[res-gap];
                res-=gap;
                count++;
            }

            arr[res]=temp;
        }
    }
    cout << "Number of insertions required to swap are: " << count << "\n";
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

    ShellSort(arr, n);

    cout << "Sorted Array is: " << "\n";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
}