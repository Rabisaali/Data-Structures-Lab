#include<iostream>
using namespace std;

string reverse(string& s, int n) {
    if (n<0) return "\0";

    //take the first char and then?
    //subtract -1?
    return s[n]+reverse(s, n-1);
}

int main() {
    string t;
    cout << "Enter the string: ";
    cin >> t;

    
    cout << reverse(t, t.length());
}