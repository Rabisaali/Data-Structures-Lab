#include<iostream>
using namespace std;

void printingarray(int arr[], int n);

void shellSort(int arr[], int n) {
    
    for(int gap = n/2; gap>0; gap/=2) {
        for(int j=gap; j<n; j++) {
            int key = arr[j];
            int res = j;

            while(res>=gap && arr[res-gap]>key) {
                arr[res]=arr[res-gap];
                res-=gap;
            }

            arr[res] = key;
        }
        cout << "Gap value: " << gap << endl;
        cout << "Partially sorted array is: ";
        printingarray(arr, n);
    }
}

void printingarray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main () {
    int arr[] = {12, 34, 54, 2, 3};
    shellSort(arr, size(arr));
    cout << "Final sorted array is: ";
    for(int i=0; i<size(arr); i++) {
        cout << arr[i] << " ";
    }
}