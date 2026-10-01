#include<iostream>
using namespace std;

class Node {
    public:
        string data;
        Node* next;

        Node(string s) {
            data = s;
            next=NULL;
        }
};

class Stack {
    public:
        Node* top;

        Stack() {
            top=NULL;
        }

        void visit(string url) {
            Node* n = new Node(url);
            if(top==NULL) {
                top=n;
            }
            else {
                n->next=top;
                top=n;
            }

            cout << "Now at: " << n->data << "\n";
        }

        void goBack() {
            if (top==NULL || top->next==NULL) {
                cout << "No previous page in history\n";
            }
            else {
                Node* temp=top;
                top=top->next;
                delete temp;
                cout << "Back to: " << top->data << "\n";
            }
        }

        void currentPage() {
            if (top==NULL) {
                cout << "No page present\n";
            }
            else {
                cout << "Current page: " << top->data << "\n";
            }
        }
};

int main () {
    Stack s;
    s.visit("google.com");
    s.visit("github.com");
    s.visit("docs.com");
    s.goBack();
    s.goBack();
    s.goBack();
}