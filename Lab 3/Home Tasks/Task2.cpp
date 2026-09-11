#include<iostream>
using namespace std;

void combSort(int arr[], int n) {
    int gap=n;
    bool swapped = true;
    int comparision=0, swaps=0;

    while(gap!=1 || swapped) {
        if (gap>1) {
            gap /= 1.3;
            if (gap<1) gap=1; 
        }
        swapped = false;

        for(int i=0; i<n-gap; i++) {
            comparision++;
            if (arr[i]>arr[i+gap]) {
                int temp = arr[i];
                arr[i] = arr[i+gap];
                arr[i+gap]=temp;
                swapped=true;
                swaps++;
            }
        }    
    }
    cout << "Comb sort comaprisions: " << comparision << "\n";
    cout << "Comb sort swaps: " << swaps << "\n";
}

void BubbleSort(int arr[], int n) {
    int swaps=0, comaprison=0;
    for(int i=0; i<n; i++) {
        for (int j=0; j<n-1; j++) {
            comaprison++;
            if (arr[j]>arr[j+1]) {
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1] = temp;
                swaps++;
            }
        }
    }
    cout << "Bubble sort comparision: " << comaprison << "\n";
    cout << "Bubble sort swaps: " << swaps << "\n";
}

void printingarray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main () {
    int arr[20];
    cout << "Enter a reverse sorted array of 20 length: ";
    for(int i=0; i<20; i++) cin >> arr[i];
    //duplicating the array so that it could be separately passed to each function
    int arr2[20];
    for (int i = 0; i < 20; i++) arr2[i] = arr[i];
    
    combSort(arr, 20);
    cout << "Sorted array by comb sort is: ";
    printingarray(arr, 20);

    BubbleSort(arr2, 20);
    cout << "Sorted array by bubble sort is: ";
    printingarray(arr2, 20);
    
}