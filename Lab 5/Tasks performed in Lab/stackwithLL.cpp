#include<iostream>
using namespace std; 

class Node {
    public:
    int val;
    Node* next;

    Node(int v) {
        val=v;
        next=NULL;
    }
};
class Stack {
    public:
        Node* head;

        Stack () {
            head=NULL;
        }

        void push(int v) {
            Node* temp=new Node(v);
            if (head==NULL) {
                head=temp;
            }
            else {
                temp->next=head;
                head=temp;
            }
        }

        int pop() {
            if (head==NULL) {
                cout << "stack is empty\n";
                return -1;
            }
            else {
                Node* temp=head;
                // while(temp->next!=tail) {
                //     temp=temp->next;
                // }
                int value=head->val;
                head=head->next;
                delete temp;
                return value;
            }
        }

        void peek() {
            if (head==NULL) {
                cout << "stack is empty\n";
                return;
            }
            else {
                cout << head->val;
            }
        }


};

int main () {
    Stack s;
    s.push(0);
    s.push(1);
    s.push(9);
    s.push(5);
    s.push(6);

    s.peek();
    cout << "\n";
    cout << s.pop() << " " << s.pop() << " " << s.pop() << " " << s.pop() << " " << s.pop() << "\n";   
    s.peek();
    //cout << s.pop() << "\n";
}

