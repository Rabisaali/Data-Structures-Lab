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
                while(pos--  && curr!=NULL) {
                    curr=curr->next;
                }

                if (curr==NULL) {
                    cout << "Invalid Position\n";
                    return;
                }

                if (curr==tail) {
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

        void deleteFromStart() {
            if (head==NULL) {
                cout << "Linked List is empty\n";
                return;
            }

            Node* temp=head->next;

            delete head;
            if (temp==NULL) {
                head=NULL;
                tail=NULL;
                return;
            }

            temp->prev=NULL;
            head=temp;
        }

        void deleteFromEnd() {
            if (head==NULL) {
                cout << "Linked List is empty\n";
                return;
            }

            Node* temp=tail->prev;
            delete tail;

            if(temp==NULL) {
                head=NULL;
                tail=NULL;
                return;
            }

            temp->next=NULL;
            tail=temp;
        }

        void deleteValue(int v) {
            Node* temp=head;

            bool found=false;
            while(!found && temp!=NULL) {
                if (temp->val==v) {
                    found=true;
                    if(temp==head) {
                        deleteFromStart();
                        return;
                    }
                    else if (temp==tail) {
                        deleteFromEnd();
                        return;
                    }

                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;

                    break;
                }
                temp=temp->next;
            }
            if (!found) {
                cout << "Value not found\n";
                return;
            }
        }

        void reverse() {
            Node* curr=head;
            while(curr!=NULL) {
                Node* temp = curr->next;
                curr->next=curr->prev;
                curr->prev=temp;

                curr=curr->prev;
                
            }
            Node* temp=head;
            head=tail;
            tail=temp;
        }
};

int main () {
    DoublyLinkedList LL;
    LL.insertAtEnd(10);
    LL.insertAtEnd(30);
    LL.insertAtPosition(1, 20);
    LL.displayForward();
    cout << endl;
    //LL.displayBackward();
    LL.reverse();
    LL.displayForward();
}