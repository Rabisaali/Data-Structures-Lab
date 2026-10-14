#include<iostream>
using namespace std;

bool isSafe(int** arr, int x, int y, int n) {
    if (x<n && y<n && arr[x][y]==1) return true;
    return false;
}

bool ratinMaze(int** arr, int x, int y, int n, int** solArr) {
    if((x==(n-1) && (y==(n-1)))) {
        solArr[x][y]=1;
        return true;
    }

    if (isSafe(arr, x, y, n)) {
        solArr[x][y]=1;

        if (ratinMaze(arr, x+1, y, n, solArr)) {
            return true;
        }

        if(ratinMaze(arr, x, y+1, n, solArr)) return true;

        solArr[x][y]=0;
        return false;
    }

    return false;
}

int main () {
    int** arr = new int*[4];
    for(int i=0; i<4; i++) arr[i]=new int[4];

    int values[4][4] = {{1,0,0,0}, {1,1,0,1}, {0,1,0,0}, {1,1,1,1}};

    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) arr[i][j] = values[i][j];
    }

    int** solArr = new int*[4];
    for(int i=0; i<4; i++) solArr[i]=new int[4];
    
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) solArr[i][j]=0;
    }

    ratinMaze(arr, 0, 0, 4, solArr);

    cout << "Solution:\n";
    for(int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            cout << solArr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i=0; i<4; i++) delete[] arr;
    delete arr;

    for (int i=0; i<4; i++) delete[] solArr;
    delete solArr;
}