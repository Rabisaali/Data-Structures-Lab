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

        void append(int val) {

            if (tail==NULL) {
                insertAtHead(val);
                return;
            }

            Node* newNode = new Node(val);
            tail->next=newNode;
            tail=newNode;
            tail->next=head; 
        }

        void insert(int pos, int val) {
            if(pos<0) {
                cout << "Invalid Position\n";
                return;
            }
            if (pos==0) {
                insertAtHead(val);
                return;
            }
            Node* curr = head;
            pos-=1;
            while(pos--) {
                curr=curr->next;
                if (curr==head) {
                    cout << "Invalid Position\n";
                    return;
                }
            }

            if (curr==tail) {
                append(val);
                return;
            }

            Node* newNode = new Node(val);
            newNode->next=curr->next;
            curr->next=newNode;
        }

        void deleteValue(int val) {
            if (head == NULL) {
                cout << "Linked List is empty\n";
                return;
            }

            Node* curr = head;
            Node* prev = tail;

            do {
                if (curr->data == val) {
                    if (curr==head && curr==tail) {
                        delete curr;
                        head = NULL;
                        tail = NULL;
                        return;
                    }

                    if (curr == head) {
                        head = head->next;
                        tail->next = head;
                        delete curr;
                        return;
                    }

                    prev->next = curr->next;

                    if (curr == tail) {
                        tail = prev;
                        tail->next = head;
                    }

                    delete curr;
                    return;
                }

                prev = curr;
                curr = curr->next;

            } while (curr!=head);

            cout << "Value not found\n";
        }

        bool search(int key) {
            Node* temp = head;

            do {
                if (temp->data == key) {
                    cout << "Value Found!" << endl;
                    return true;
                }
                temp=temp->next;
            } while(temp!=head);
            cout << "Value not found\n";
            return false;
        }
};


int main () {
    CircularLinkedList LL;
    LL.append(90);
    LL.append(8);
    LL.insert(0, 9);
    LL.insert(3, 10);
    LL.display();
    cout << endl;
    cout << "Deleting 10\n";
    LL.deleteValue(10);
    LL.display();
    cout << endl;
    cout << "Searching for 8\n";
    
    bool exp = LL.search(8);

    cout << "Searching for 67\n";
    bool exp2 = LL.search(67);
}
