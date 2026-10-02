#include<iostream>
using namespace std;

class Stack {
    public:
        int n;
        int* arr;
        int top=-1;

        Stack(int len) {
            arr = new int [len];
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

        int peek() {
            if (top==-1) {
                cout << "Stack is empty\n";
                return -1;
            }
            else {
                return arr[top];
            }
        }

        void push(int c) {
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

bool isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/');
}

int main () {
    string s;
    cout << "Input: ";
    cin >> s;
    Stack st(s.length());
    for(int i=0; i<s.length(); i++) {
        if (!isOperator(s[i]) && s[i] >= '0' && s[i] <= '9') st.push(s[i]-'0'); 
        else {
            int x1, x2;
            bool flag=false;
            if (!st.isEmpty()) {
                x1=st.peek();
                st.pop();
            }
            else flag=true;

            if (!st.isEmpty()) {
                x2=st.peek();
                st.pop();
            }
            else flag=true;

            if (flag) {
                cout << "Output: Error: Malformed expression\n";
                return -1;
            }

            if (s[i]=='*') st.push(x1*x2);
            else if (s[i]=='/') st.push(x2/x1);
            else if (s[i]=='+') st.push(x1+x2);
            else if (s[i]=='-') st.push(x2-x1);
        }
    }
    if (st.isEmpty()) {
        cout << "Output: Error: Malformed expression\n";
        return -1;
    }
    int x=st.peek();
    st.pop();
    if (!st.isEmpty()) {
        cout << "Output: Error: Malformed expression\n";
        return -1;
    }
    else cout << "Output: " << x << endl;
}