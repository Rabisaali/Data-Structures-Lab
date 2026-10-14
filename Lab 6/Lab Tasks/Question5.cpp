#include<iostream>
using namespace std;

int factorial (int n, int accumulator=1) {
    if (n==0) return accumulator;
    return factorial(n-1, n*accumulator);
}

int main () {
    int n;
    cout << "Enter the number: ";
    cin >> n;

    int ans=factorial(n);
    cout << "The answer of the factorial is: " << ans << endl;
}