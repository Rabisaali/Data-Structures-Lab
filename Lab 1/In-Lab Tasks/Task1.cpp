#include<iostream>
#include<iomanip>
using namespace std;

int main () {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int* arr = new int[n];

    for(int i=0; i<n; i++) {
        cout << "Enter element " << i+1 << ": ";
        cin >> *(arr+i);
    }

    int sum=0, maximum=arr[0], minimum=arr[0];
    float average=0;

    for(int i=0; i<n; i++) {
        if (*(arr+i)>maximum) maximum = *(arr+i);
        if (*(arr+i)<minimum) minimum = *(arr+i);

        sum += *(arr+i);
    }

    average = float(sum)/float(n);
    cout << endl;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << setprecision(5) << average  << endl;
    cout << "Maximum: " << maximum << endl;
    cout << "Minimum: " << minimum << endl;
}