#include<iostream>
using namespace std;

string reverse(string& s, int n) {
    if (n<0) return "";

    return s[n]+reverse(s, n-1);
}

int main() {
    string t;
    cout << "Enter the string: ";
    cin >> t;

    
    cout << reverse(t, t.length()-1);
}