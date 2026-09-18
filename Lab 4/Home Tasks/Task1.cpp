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
};

int main () {

}