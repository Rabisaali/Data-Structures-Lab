#include<iostream>
using namespace std;

bool plaindromechecker(string s, int i, int n) {
    if (i==n/2) {
        if (s[i]==s[n-i-1]) return true;
        else return false;
    }
    bool ans;
    if (s[i]==s[n-i-1]) {
        ans = plaindromechecker(s, i+1, n);
    }
    else return false;
    return ans;
}

int main () {
    string s;
    cout << "Enter the string to be checked: ";
    cin >> s;
    if (plaindromechecker(s, 0, s.length())) cout << "The above string is a plindrome :)\n";
    else cout << "The above string is not a palindrome :(\n";
}