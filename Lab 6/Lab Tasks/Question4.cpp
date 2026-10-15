#include<iostream>
using namespace std;

bool palindromechecker(string& s, int i, int n) {
    if(i>=n/2) return true;
    
    if (s[i]==s[n-i-1]) return palindromechecker(s, i+1, n);
    else return false;

}

int main () {
    string s;
    cout << "Enter the string to be checked: ";
    cin >> s;
    if (palindromechecker(s, 0, s.length())) cout << "The above string is a plindrome :)\n";
    else cout << "The above string is not a palindrome :(\n";
}