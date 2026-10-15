#include<iostream>
#include<cstdlib>
using namespace std;

bool isSafe(int board[], int row, int col) {
    for(int i=0; i<row; i++) {
        if (board[i]==col || abs(board[i]-col)==abs(i-row)) return false;
    }
    return true;
}

bool solveNQueens(int board[], int n, int row=0) {
    if (row==n) return true;
    for(int col=0; col<n; col++) {
        if(isSafe(board, row, col)) {
            board[row]=col;
            if(solveNQueens(board, n, row+1)) return true;
            board[row]=-1;
        }
    }
    return false;
}

void printBoard(int board[], int n) {
    for(int r=0; r<n; r++) {
        for(int c=0; c<n; c++) {
            cout << (board[r] == c ? "Q " : ". ");
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

    if(solveNQueens(board, n)) printBoard(board, n);
    else cout << "No solution exists\n";

    delete[] board;
}

/*The algorithm uses recursion and backtracking to place one queen in each row. It checks whether each position is safe before placing a queen. If no valid position is available in a later row, it backtracks and tries a different position. For N = 2 and N = 3, no arrangement satisfies the constraints, so the function returns `false` and the program prints "No solution exists."*/