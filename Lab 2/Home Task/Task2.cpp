#include<iostream>
using namespace std;

int main () {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    int** arr;
    arr = new int* [n];

    int Size[n];

    for(int i=0; i<n; i++) {
        int x;
        cout << "How many courses is student " << i+1 << " enrolled in: ";
        cin >> x;
        Size[i] = x;
        cout << endl;
    }

    for(int i=0; i<n; i++) {
        arr[i] = new int [Size[i]];
    }

    cout << "Enter numbers of each course respectively: " << endl;

    for(int i=0; i<n; i++) {
        cout << "Student " << i+1 << " - courses: " << Size[i] << " -> marks: ";
        for(int j=0; j<Size[i]; j++) {
            cin >> arr[i][j];
        }
        cout << endl;
    }

    double average[n];

    cout << "Displaying each student's marks: " << endl;
    for(int i=0; i<n; i++) {
        cout << "Student " << i+1 << " - courses: " << Size[i] << " -> marks: ";
        for(int j=0; j<Size[i]; j++) {
            cout << arr[i][j] << " ";
            average[i] += arr[i][j];
        }
        average[i] /= Size[i];
        cout << endl;
    }

    int max_average=average[0], min_average=average[0];
    int max_ind=1, min_ind=1;

    for(int i=0; i<n; i++) {
        cout << "Student " << i+1 << " average: " << average[i];
        if (average[i]>max_average) {
            max_average=average[i];
            max_ind = i+1;
        }
        if (average[i]<min_average) {
            min_average=average[i];
            min_ind=i+1;
        }
    }

    cout << "Highest average: Student " << max_ind << " | Lowest average: Student " << min_ind << endl;

    int choice;
    cout << "To insert a new mark entry for a specific student enter 1 else enter 0";
    cin >> choice;
    if (choice == 1) {
        
    }



    
    
}