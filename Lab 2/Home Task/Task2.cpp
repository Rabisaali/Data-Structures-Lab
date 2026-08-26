#include<iostream>
using namespace std;

int* addingNewMarks(int* array, int courses) {
    int* row = new int[courses+1];
    for(int i=0; i<courses; i++) {
        row[i] = array[i];
    }
    cout << "Enter new mark: ";
    cin >> row[courses];
    delete[] array;
    return row;
}

int main () {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    int** arr;
    arr = new int* [n];

    int* Size = new int[n];
    double* average = new double[n]();

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

    cout << "Enter marks for each student: " << endl;

    for(int i=0; i<n; i++) {
        cout << "Student " << i+1 << " - courses: " << Size[i] << " -> marks: ";
        for(int j=0; j<Size[i]; j++) {
            cin >> arr[i][j];
        }
        cout << endl;
    }

    cout << "Displaying each student's marks: " << endl;
    for(int i=0; i<n; i++) {
        cout << "Student " << i+1 << " - courses: " << Size[i] << " -> marks: ";
        for(int j=0; j<Size[i]; j++) {
            cout << arr[i][j] << " ";
            average[i] += arr[i][j];
        }
        average[i] /= double(Size[i]);
        cout << endl;
    }

    double max_average=average[0], min_average=average[0];
    int max_ind=1, min_ind=1;

    for(int i=0; i<n; i++) {
        cout << "Student " << i+1 << " average: " << average[i] << endl;
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
    cout << "To insert a new mark entry for a specific student enter 1 else enter 0: ";
    cin >> choice;
    if (choice == 1) {

        int student=0;
        cout << "Enter the student number for whom you want to add the new marks (1-based indexing): ";
        cin >> student;

        if (student >= 1 && student <= n) {
            arr[student-1] = addingNewMarks(arr[student-1], Size[student-1]);
            Size[student-1]++;
            cout << "The new marks array is: " << endl;
            for (int i = 0; i < n; i++) {
                average[i] = 0;
            }

            cout << "Displaying each student's marks: " << endl;
            for(int i=0; i<n; i++) {
                cout << "Student " << i+1 << " - courses: " << Size[i] << " -> marks: ";
                for(int j=0; j<Size[i]; j++) {
                    cout << arr[i][j] << " ";
                    average[i] += arr[i][j];
                }
                average[i] /= double(Size[i]);
                cout << endl;
            }

            double max_average=average[0], min_average=average[0];
            int max_ind=1, min_ind=1;

            for(int i=0; i<n; i++) {
                cout << "Student " << i+1 << " average: " << average[i] << endl;
                if (average[i]>max_average) {
                    max_average=average[i];
                    max_ind = i+1;
                }
                if (average[i]<min_average) {
                    min_average=average[i];
                    min_ind=i+1;
                }
            }

            cout << "New highest average: Student " << max_ind << " | New lowest average: Student " << min_ind << endl;
        }

        else {
            cout << "Invalid student number." << endl;
        }
    }

    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }

    delete[] arr;
    delete[] Size;
    delete[] average;
}