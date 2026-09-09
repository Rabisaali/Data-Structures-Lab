#include<iostream>
using namespace std;

int main () {
    int arr[5];
    cout << "Enter a sorted array of size 5: ";
    for(int i=0; i<5; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the element you need to find: ";
    cin >> key;

    int left = 0, right=4;

    while(left<=right) {
        int mid = left+(right-left)/2;
        if(arr[mid]==key) {
            cout << "Your element " << arr[mid] << " has been found at position " << mid << "\n";
            return 0;
        }
        else if (arr[mid]<key) {
            left = mid+1;
        }
        else {
            right = mid-1;
        }
    }

    cout << "Your element is not in the array that you provided\n";
}