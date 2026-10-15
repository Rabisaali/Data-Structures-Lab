#include<iostream>
#include <chrono>
using namespace std;

long long fib(int n) {
    if (n<=1) return n;

    return fib(n-1)+fib(n-2);
}

long long memo_fib(int n, long long* memo) {
    if (n<=1) return n;

    if (memo[n]!=-1) return memo[n];

    return memo[n]=memo_fib(n-1, memo)+memo_fib(n-2, memo);
}

int main () {
    int n=40;
    auto start = chrono::high_resolution_clock::now();
    cout << "The answer through normal fib function: ";
    cout << fib(n) << "\n";
    auto end = chrono::high_resolution_clock::now();
    long long time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "The time taken is: " << time << " milliseconds" << endl;


    long long* memo = new long long[n + 1];
    for(int i=0; i<=n; i++) {
        memo[i]=-1;
    }

    start = chrono::high_resolution_clock::now();
    cout << "The answer through memoized fib funtion: ";
    cout << memo_fib(n, memo) << "\n";
    end = chrono::high_resolution_clock::now();
    time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "The time taken is: " << time << " milliseconds" << endl;

    delete[] memo;

}