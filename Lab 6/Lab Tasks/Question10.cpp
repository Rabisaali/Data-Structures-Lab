#include<iostream>
#include<cstdlib>
using namespace std;

bool isSafe(int board[], int row, int col) {
    for(int i=0; i<row; i++) {
        if (board[i]==col || abs(board[i]-col)==abs(i-row)) return false;
    }
    return true;
}

int solveNQueens(int board[], int n, int row=0) {
    if (row==n) return 1;
    int count=0;
    for(int col=0; col<n; col++) {
        if(isSafe(board, row, col)) {
            board[row]=col;
            count+=(solveNQueens(board, n, row+1));
            board[row]=-1;
        }
    }
    return count;
}

void printBoard(int board[], int n) {
    for(int r=0; r<n; r++) {
        for(int c=0; c<n; c++) {
            cout << (board[r] == c ? "Q" : ". ");
        }
        cout << endl;
    }
}

int main () {
    int n;
    cout << "Enter n: ";
    cin >> n;
    int* board = new int[n];
    for(int i=0; i<n; i++) board[i]=-1;

    int total = solveNQueens(board, n);
    cout << "Total Solutions: " << total << endl;
    delete[] board;
    
}