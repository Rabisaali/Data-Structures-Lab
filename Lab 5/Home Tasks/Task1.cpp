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

int getPrecedence(char c) {
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

    string t="";

    if(!validate(s)) {
        cout << "Invalid expression\n";
        return 0;
    }

    Stack st(s.length());
    cout << "Output: ";
    for(int i=s.length()-1; i>=0; i--) {
        if (!isOpertaor(s[i])) t = s[i]+t;
        else {
            if (s[i]==')') st.push(')');
            else if (s[i]=='(') {
                while(!st.isEmpty() && st.peek()!=')') {
                    t = st.peek()+t;
                    st.pop();
                }

                if(!st.isEmpty() && st.peek()==')') {
                    st.pop();
                }
            }
            else {
                while(!st.isEmpty() && getPrecedence(st.peek()) >= getPrecedence(s[i])) {  
                    t = st.peek()+t;
                    st.pop();
                }
                st.push(s[i]);
            }
        }
    }
    while(!st.isEmpty()) {
        t = st.peek()+t;
        st.pop();
    }

    cout << t;
    cout << endl;
}