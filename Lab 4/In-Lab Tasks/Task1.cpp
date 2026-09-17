#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int v) {
            data=v;
            next=NULL;
        }
};

class SinglyLinkedList {
    public:
        Node* head;

        SinglyLinkedList() {
            head=NULL;
        }

        void display() {
            Node* temp=head;

            while(temp!=NULL) {
                cout << temp->data << " -> ";
                temp=temp->next;
            }
            cout << "NULL\n";
        }
};

int main() {
    SinglyLinkedList ll;
    ll.display();
}