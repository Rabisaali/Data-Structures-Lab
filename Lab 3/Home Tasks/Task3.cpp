// int pos = low + ((key - arr[low]) * (high - low) / (arr[high] - arr[low]));

#include<iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int key) {
    int low = 0;
    int high = n-1;
    int it = 0;
    while(low<=high && key>=arr[low] && key<=arr[high]) {
        it++;
        if (arr[low]==arr[high]) {
            if (arr[low]==key) {
                cout << "Interpolation search iterations: " << it << "\n";
                return low;
            }
            else break;
        }

        int pos = low + ((key - arr[low]) * (high - low) / (arr[high] - arr[low]));

        if (arr[pos]==key) {
            cout << "Interpolation search iterations: " << it << "\n";
            return pos;
        }
        else if (arr[pos]<key) low = pos+1;
        else high = pos-1;
    }
    cout << "Interpolation search iterations: " << it << "\n";
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int left = 0, right=n-1;
    int it=0;
    while(left<=right) {
        it++;
        int mid = left+(right-left)/2;
        if(arr[mid]==key) {
            cout << "Binary search iterations: " << it << "\n";
            return mid;
        }
        else if (arr[mid]<key) {
            left = mid+1;
        }
        else {
            right = mid-1;
        }
    }
    cout << "Binary search iterations: " << it << "\n";
    return -1;
}

int main () {
    int arr[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100};
    int size = 20;

    cout << "Finding 60 in the uniformly distributed sorted array of multiples of 5 by interpolation search: " << "\n";
    int x = interpolationSearch(arr, size, 60);
    if (x!=-1) cout << "60 is present at position: " << x << "\n";
    else cout << "60 is not present in the array\n";
    cout << endl;

    cout << "Finding 3 in the uniformly distributed sorted array of multiples of 5 by interpolation search:\n";
    int z = interpolationSearch(arr, size, 3);
    if (z!=-1) cout << "3 is present at position: " << z << "\n";
    else cout << "3 is not present in the array\n";
    cout << endl << endl;


    int arr2[] = {1, 2, 3, 4, 5, 1000};
    int size2 = 6;

    cout << "Finding 1000 in the non-uniform sorted array by interpoloation search:\n";
    int y = interpolationSearch(arr2, size2, 1000);
    if (y!=-1) cout << "1000 is present at position: " << y << "\n";
    else cout << "1000 is not present in the array\n";
    cout << endl;

    cout << "Finding 1000 in the non-uniform sorted array by binary search:\n";
    int t = binarySearch(arr2, size2, 1000);
    if (t!=-1) cout << "1000 is present at position: " << t << "\n";
    else cout << "1000 is not present in the array\n";
}


// Interpolation Search has an average-case complexity of O(log log n) when the sorted data is approximately uniformly distributed because its position estimate can jump very close to the target. For highly non-uniform data, the estimated positions can be poor, causing the search range to shrink very slowly, so its performance can degrade to O(n).