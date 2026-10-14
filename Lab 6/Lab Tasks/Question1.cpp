#include<iostream>
using namespace std;

int sum(int s) {
    if (s<10) return s;

    return s%10+sum(s/10);
}

int main () {
    long long num;
    cout << "Enter the number: ";
    cin >> num;
    cout << "The sum of digits: ";
    cout << sum(num);
}