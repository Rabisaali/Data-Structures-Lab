#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data=val;
        next=NULL;
        prev=NULL;
    }
};

class Doubly {
    public:
        Node* head;
        Node* tail;

        Doubly() {
            head=NULL;
            tail=NULL;
        }

        void insertAt(int data, int pos) {
            if (pos < 0) {
                cout << "Invalid position." << endl;
                return;
            }

            Node* newNode = new Node(data);

            if (pos == 0) {
                newNode->next = head;
                if (head != NULL) head->prev = newNode;
                else  tail = newNode; 

                head = newNode;
                return;
            }

            Node* curr = head;

            for (int i = 0; i < pos - 1 && curr != NULL; i++) {
                curr = curr->next;
            }

            if (curr == NULL) {
                cout << "Position out of bounds." << endl;
                delete newNode;
                return;
            }

            newNode->next = curr->next;
            newNode->prev = curr;

            if (curr->next != NULL) curr->next->prev = newNode;
            else tail = newNode; 

            curr->next = newNode;
        }

        void reverseTraversal() {
            if(tail==NULL) {
                cout << "Linked List is empty\n";
                return;
            }
            Node* curr = tail;
            while(curr->prev!=NULL) {
                cout << curr->data << " -> ";
                curr = curr->prev;
            }
            cout << curr->data;
        }
};

int main () {
    Doubly LL;
    LL.insertAt(3, 0);
    LL.insertAt(4, 1);
    LL.insertAt(9, 2);
    LL.insertAt(10, 3);

    LL.reverseTraversal();
}