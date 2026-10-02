#include<iostream>
using namespace std;

class Stack {
    public:
        int n;
        char* arr;
        int top=-1;

        Stack(int len) {
            arr = new char [len];
            n=len;
        }

        void pop() {
            if (top==-1) {
                cout << "Stack is empty\n";
                return;
            }
            else {
                top--;
            }
        }

        char peek() {
            if (top==-1) {
                cout << "Stack is empty\n";
                return '\0';
            }
            else {
                return arr[top];
            }
        }

        void push(char c) {
            arr[++top]=c;
        }

        bool isEmpty() {
            if (top==-1) return true;
            else return false;
        }

        ~Stack() {
            delete[] arr;
        }

};

bool validate(string s) {
    Stack st(s.length());

    for(int i=0; i<s.length(); i++) {
        if (s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
        else if (s[i]==')') {
            if(st.isEmpty() || st.peek()!='(') return false;
            st.pop();
        }
        else if (s[i]=='}') {
            if(st.isEmpty() || st.peek()!='{') return false;
            st.pop();
        }
        else if (s[i]==']') {
            if(st.isEmpty() || st.peek()!='[') return false;
            st.pop();
        }
    }

    if (st.isEmpty()) return true;
    else return false;
}

int main () {
    string s;
    cout << "Input: ";
    cin >> s;
    cout << "Output: ";
    if (validate(s)) cout << "Balanced\n";
    else cout << "Not Balanced\n";
}