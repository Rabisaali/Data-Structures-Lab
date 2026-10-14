#include<iostream>
using namespace std;

int power(int x, int n) {
    if (n==0) return 1;

    return x*power(x, n-1);
}

int Power(int x, int n) {
    if (n==0) return 1;

    int ans = Power(x, n/2);

    if (n%2) {
        return x*ans*ans;
    }
    else return ans*ans;
}

int main () {

    int num;
    cout << "Enter the number: ";
    cin >> num;
    int pow;
    cout << "Enter the power: ";
    cin >> pow;

    cout << "(Slower approach) The answer is: ";
    cout << power(num, pow) << "\n";

    cout << "(Optimized approach) The answer is: ";
    cout << Power(num, pow) << "\n";
}   