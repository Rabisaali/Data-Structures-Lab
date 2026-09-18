#include<iostream>
using namespace std;

class Node {
    public:
        string data;
        Node* next;

        Node(string val) {
            data=val;
            next=NULL;
        }
};

class CircularLinkedList {
    public:
        Node* head;
        Node* tail;
        Node* turn;

        CircularLinkedList() {
            head=tail=NULL;
            turn=head;
        }

        void insertAtHead(string val) {
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

        void nextTurn() {
            cout << turn->data << " ";
            turn=turn->next;
        }

        void removePlayer(string name) {
            if (head==NULL) {
                cout << "Linked list is empty\n";
                return;
            }

            Node* curr = head;
            Node* prev = tail;

            do {
                if (curr->data==name) {
                    if (curr==head && curr==tail) {
                        delete curr;
                        head=NULL;
                        tail=NULL;
                        turn=NULL;
                        return;
                    }

                    if (curr==turn) {
                        turn=curr->next;
                    }

                    if (curr==head) {
                        head=head->next;
                        tail->next=head;
                        delete curr;
                        return;
                    }

                    prev->next=curr->next;

                    if (curr==tail) {
                        tail=prev;
                        tail->next=head;
                    }
                    delete curr;
                    return;
                }
                prev=curr;
                curr=curr->next;

            } while(curr!=head);

        }

        void startTurn() {
            if (head != NULL) turn=head->next;
        }
        
};


int main () {
    CircularLinkedList LL;
    
    LL.insertAtHead("Cara");
    LL.insertAtHead("Beena");
    LL.insertAtHead("Ali");
    LL.startTurn();
    LL.nextTurn();
    LL.nextTurn();
    LL.nextTurn();
    LL.nextTurn();
}
