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

class CircularLinkedList {
    public:
        Node* head;
        Node* tail;

        CircularLinkedList() {
            head=tail=NULL;
        }

        void insertAtHead(int val) {
            Node* newNode = new Node(val);
            if (head==NULL) {
                head=newNode;
                tail=head;
                tail->next=head;
            }
            else {
                newNode->next=head;
                head=newNode;
                tail->next=head;
            }
        }

        void display() {

            if (head == NULL) {
                cout << "Linked List is empty\n";
                return;
            }

            Node* temp = head;

            do {
                cout << temp->data << " ";
                temp=temp->next;
            } while(temp!=head);
        }
};


int main () {
    CircularLinkedList LL;
    LL.insertAtHead(9);
    LL.insertAtHead(10);
    LL.insertAtHead(11);
    LL.display();
}
