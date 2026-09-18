#include<iostream>
using namespace std;

class Node {
    public:
        int val;
        Node* prev;
        Node* next;

        Node(int v) {
            val=v;
            prev=next=NULL;
        }
};

class DoublyLinkedList {
    public:
        Node* head;
        Node* tail;

        DoublyLinkedList() {
            head=tail=NULL;
        }

        void displayForward() {
            if (head == NULL && tail == NULL) {
                cout << "Linked List is empty\n";
                return;
            }
            else {
                Node* temp = head;
                while(temp!=NULL) {
                    cout << temp->val << " <-> ";
                    temp=temp->next;
                }
                cout << "NULL\n";
            }
        }

        void displayBackward() {
            if (head == NULL && tail == NULL) {
                cout << "Linked List is empty\n";
                return;
            }
            else {
                Node* temp=tail;
                while(temp!=NULL) {
                    cout << temp->val << " <-> ";
                    temp=temp->prev;
                }
                cout << "NULL\n";
            }
        }

        void insertAtStart(int val) {
            Node* newNode = new Node(val);
            if (head==NULL && tail==NULL) {
                head=newNode;
                tail=newNode;
                return;
            }
            else {
                head->prev=newNode;
                newNode->next=head;
                newNode->prev=NULL;
                head=newNode;
                return;
            }
        }

        void insertAtEnd(int val) {
            Node* newNode = new Node(val);
            if (head==NULL && tail==NULL) {
                head=newNode;
                tail=newNode;
                return;
            }
            else {
                tail->next=newNode;
                newNode->prev=tail;
                newNode->next=NULL;
                tail=newNode;
                return;
            }
        }

        void insertAtPosition(int pos, int val) {
            if (pos==0) {
                insertAtStart(val);
                return;
            }
            else {
                Node* curr=head;
                pos-=1;
                while(pos--) {
                    curr=curr->next;
                }

                if (curr==NULL) {
                    cout << "Invalid Position\n";
                    return;
                }

                if (curr=tail) {
                    insertAtEnd(val);
                   return;
                }

                Node* newNode = new Node(val);
                
                newNode->next=curr->next;
                newNode->prev=curr;
                curr->next->prev=newNode;
                curr->next=newNode;
            }
        }
};

int main () {
    DoublyLinkedList LL;
    LL.insertAtEnd(10);
    LL.insertAtEnd(30);
    LL.insertAtPosition(1, 20);
    LL.displayForward();
    cout << endl;
    LL.displayBackward();
}