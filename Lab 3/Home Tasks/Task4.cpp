#include<iostream>
#include<random>
#include <chrono>
#include <iomanip>
using namespace std;
#define int long long

void BubbleSort(int arr[], int n) {

    for(int i=0; i<n; i++) {
        for (int j=0; j<n-1; j++) {
            if (arr[j]>arr[j+1]) {
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void SelectionSort(int arr[], int n) {

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
    }
}

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

void ShellSort(int arr[], int n) {

    for(int gap = n/2; gap>0; gap/=2) {
        for(int j=gap; j<n; j++) {
            int temp = arr[j];
            int res = j;

            while(res>=gap && arr[res-gap]>temp) {
                arr[res]= arr[res-gap];
                res-=gap;
            }

            arr[res]=temp;
        }
    }
}

void CombSort(int arr[], int n) {

    int gap=n;
    bool swapped = true;

    while(gap!=1 || swapped) {
        if (gap>1) {
            gap /= 1.3;
            if (gap<1) gap=1; 
        }
        swapped = false;

        for(int i=0; i<n-gap; i++) {
            if (arr[i]>arr[i+gap]) {
                int temp = arr[i];
                arr[i] = arr[i+gap];
                arr[i+gap]=temp;
                swapped=true;
            }
        }    
    }
}

int* arrayGeneration(int size) {
    int* arr = new int[size];
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> range(0, size-1);

    for(int i=0; i<size; i++) {
        arr[i] = range(gen);
    } 
    return arr;   
}

int* copyArray(int arr[], int n) {
    int* copy = new int[n];

    for(int i = 0; i < n; i++) {
        copy[i] = arr[i];
    }

    return copy;
}

int getTime(void (*sortFunction)(int[], int), int arr[], int n) {

    int* temp = copyArray(arr, n);
    auto start = chrono::high_resolution_clock::now();
    sortFunction(temp, n);
    auto end = chrono::high_resolution_clock::now();
    int time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    delete[] temp;

    return time;
}

signed main() {
    int sizes[] = {100, 1000, 10000, 50000};

    for (int s = 0; s < 4; s++) {
        int n = sizes[s];
        int* arr = arrayGeneration(n);

        int bubbleTime = getTime(BubbleSort, arr, n);

        int selectionTime = getTime(SelectionSort, arr, n);

        int insertionTime = getTime(InsertionSort, arr, n);

        int shellTime = getTime(ShellSort, arr, n);

        int combTime = getTime(CombSort, arr, n);

        cout << "Size: " << n << endl << endl;
        cout << "Bubble Sort: " << bubbleTime << endl << "Selection Sort: " << selectionTime << endl << "Insertion Sort: " << insertionTime << endl << "Shell Sort: " << shellTime << endl << "Comb Sort: " << combTime << endl;
        cout << endl;

        delete[] arr;
    }

    int n = 10000;
    cout << endl << endl;

    // Generate random array
    int* randomArr = arrayGeneration(n);

    // Make copies
    int* sortedArr = copyArray(randomArr, n);
    int* reverseArr = copyArray(randomArr, n);

    // Sort sortedArr
    // We use Shell Sort only to PREPARE the test data.
    // This preparation is NOT being timed.
    ShellSort(sortedArr, n);

    // Create reverse-sorted array from sorted array
    for (int i = 0; i < n; i++) {
        reverseArr[i] = sortedArr[n - 1 - i];
    }

    cout << endl;

    cout << endl;
    cout << "Random Array (n=10000):" << endl;

    cout << "Bubble Sort: " << getTime(BubbleSort, randomArr, n) << endl << "Selection Sort: " << getTime(SelectionSort, randomArr, n) << endl << "Insertion Sort: " << getTime(InsertionSort, randomArr, n) << endl << "Shell Sort: " << getTime(ShellSort, randomArr, n) << endl << "Comb Sort: " << getTime(CombSort, randomArr, n) << endl;
    cout << endl;

    cout << endl;
    cout << "Already Sorted Array (n=10000):" << endl;

    cout << "Bubble Sort: " << getTime(BubbleSort, sortedArr, n) << endl << "Selection Sort: " << getTime(SelectionSort, sortedArr, n) << endl << "Insertion Sort: " << getTime(InsertionSort, sortedArr, n) << endl << "Shell Sort: " << getTime(ShellSort, sortedArr, n) << endl << "Comb Sort: " << getTime(CombSort, sortedArr, n) << endl;
    cout << endl;

    cout << endl;
    cout << "Reverse Sorted Array (n=10000):" << endl;

    cout << "Bubble Sort: " << getTime(BubbleSort, reverseArr, n) << endl << "Selection Sort: " << getTime(SelectionSort, reverseArr, n) << endl << "Insertion Sort: " << getTime(InsertionSort, reverseArr, n) << endl << "Shell Sort: " << getTime(ShellSort, reverseArr, n) << endl << "Comb Sort: " << getTime(CombSort, reverseArr, n) << endl;
    cout << endl;

    delete[] randomArr;
    delete[] sortedArr;
    delete[] reverseArr;

    return 0;
}