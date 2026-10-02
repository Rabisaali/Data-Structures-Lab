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

int precedence(char c) {
    switch(c) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

bool validate(string s) {
    Stack st(s.length());

    for(int i=0; i<s.length(); i++) {
        if (s[i]=='(') st.push('(');
        else if (s[i]==')') {
            if(st.isEmpty()) return false;
            st.pop();
        }
    }

    if (st.isEmpty()) return true;
    else return false;
}

bool isOpertaor(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='(' || c==')');
}


int main () {
    string s;
    cout << "Input: ";
    cin >> s;

    if(!validate(s)) {
        cout << "Invalid expression\n";
        return 0;
    }

    Stack st(s.length());
    cout << "Output: ";
    for(int i=0; i<s.length(); i++) {
        if (!isOpertaor(s[i])) cout << s[i];
        else {
            if (s[i]=='(') st.push('(');
            else if (s[i]==')') {
                while(!st.isEmpty() && st.peek()!='(') {
                    cout << st.peek();
                    st.pop();
                }

                if(!st.isEmpty() && st.peek()=='(') {
                    st.pop();
                }
            }
            else {
                while(!st.isEmpty() && (precedence(st.peek()) > precedence(s[i]) || (precedence(st.peek()) == precedence(s[i]) && s[i] != '^'))) {  
                    cout << st.peek();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
    }
    while(!st.isEmpty()) {
        cout << st.peek();
        st.pop();
    }
    cout << endl;
}