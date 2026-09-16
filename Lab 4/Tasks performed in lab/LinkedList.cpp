#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int val) {
        data=val;
        next=NULL;
    }
};

class Singly {
    public:
        Node* head;
        Node* tail;

        Singly() {
            head=NULL;
            tail=NULL;
        }

        void insertAt(int pos, int val) {
            if(pos<0) {
                cout << "Invalid position\n";
                return;
            }
            Node* newNode = new Node(val);
            if(pos==0) {
                newNode->next=head;
                head=newNode;
                return;
            }
            Node* temp=head;
            for(int i=0; i<pos-1; i++) {
                if(temp==NULL) {
                    cout << "Invalid position\n";
                    return;
                }
                temp=temp->next;
            }

            
            newNode->next = temp->next;
            temp->next=newNode;
        }

        bool search(int key) {
            Node* temp=head;

            while(temp!=NULL) {
                if (temp->data==key) {
                    cout << "Found\n";
                    return true;
                }
                temp=temp->next;
            }

            cout << "Not Found\n";
            return false;
        }

        void display() {
            Node* temp=head;
            while(temp!=NULL) {
                cout << temp->data << " ";
                temp=temp->next;
            }
        }
};

int main () {
    Singly s;
    s.insertAt(0, 9);
    s.insertAt(1, 8);
    s.insertAt(2, 18);
    s.insertAt(0, 7);
    s.display();
    cout << endl;
    s.search(9);
    s.search(0);
}

