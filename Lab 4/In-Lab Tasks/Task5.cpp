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
        Node* tail;

        SinglyLinkedList() {
            head=tail=NULL;
        }

        void display() {
            Node* temp=head;

            while(temp!=NULL) {
                cout << temp->data << " -> ";
                temp=temp->next;
            }
            cout << "NULL\n";
        }

        void insertAtStart(int val) {
            Node* newNode = new Node(val);

            if (head==NULL) {
                head=tail=newNode;
            }
            else {
                newNode->next=head;
                head=newNode;
            }

        }

        void insertAtEnd(int val) {
            Node* newNode = new Node(val);
            if (tail==NULL) head=tail=newNode;
            else {
                tail->next=newNode;
                tail=newNode;
            } 
        }

        void insertAfter(int pos, int val) {
            // if (pos==-1) {
            //     insertAtStart(val);
            //     return;
            // }
            if (pos<0) {
                cout << "Invalid Index\n";
                return;
            }
            
            Node* temp=head;
            while(pos--) {
                if (temp==NULL) {
                    cout << "Invalid index\n";
                    return;
                }
                temp=temp->next;
            }

            if (temp == NULL) {
                cout << "Invalid index\n";
                return;
            }

            Node* newNode=new Node(val);
            newNode->next=temp->next;
            temp->next=newNode;

            if(temp==tail) tail=newNode;
            return;
        }

        int search (int key) {
            Node* temp=head;
            int i=0;
            while(temp!=NULL) {
                if (temp->data==key) {
                    cout << "Key found!";
                    return i;
                }
                i++;
                temp=temp->next;
            }
            cout << "Key not found! Returning -1\n";
            return -1;
        }

        int countNodes() {
            int value=0;
            Node* temp=head;

            while(temp != NULL) {
                value++;
                temp=temp->next;
            }
            return value;
        }

        int sumOfNodes() {
            int sum=0;
            Node* temp=head;
            while(temp!=NULL) {
                sum+=temp->data;
                temp=temp->next;
            }
            return sum;
        }

        void deleteFromStart() {
            if (head==NULL) {
                cout << "Linked List is empty\n";
                return;
            }
            Node* temp = head->next;
            delete head;
            head=temp;

            if(head==NULL) tail=NULL;
        }

        void deleteFromEnd() {
            if (head==NULL) {
                cout << "Linked List is empty\n";
                return;
            }

            if (head->next==NULL) {
                delete head;
                head=tail=NULL;
                return;
            }

            Node* temp=head;
            while(temp->next->next!=NULL) {
                temp=temp->next;
            }
            delete temp->next;  
            temp->next=NULL;
            tail=temp;
        }

        void deleteAfter(int pos) {
            if(pos==-1) {
                deleteFromStart();
                return;
            }
            if (pos<-1) {
                cout << "Invalid index\n";
                return;
            }
            Node* curr=head;
            while(pos--) {
                if(curr==NULL) {
                    cout << "Invalid index\n";
                    return;
                }
                curr=curr->next;
            }
            if (curr == NULL || curr->next == NULL) {
                cout << "Invalid index\n";
                return;
            }
            Node* temp=curr->next;
            curr->next=temp->next;

            if(temp==tail) tail=curr;
            delete temp;
        }

};

int main() {
    SinglyLinkedList ll;
    int choice=0;
    do {
        cout << "Menu: " << endl;
        cout << "To insert an element in LL enter 1\nTo delete an element from LL enter 2\nTo search for an element in LL enter 3\nTo display the LL enter 4\nTo exit enter 0\nChoice: ";
        cin >> choice;
        switch(choice) {
            case 1: {
                int choice2;
                cout << "To insert an element at start enter 10\nTo insert an element at end enter 11\nTo insert an element after a position enter 12\nChoice: ";
                cin >> choice2;
                switch(choice2) {
                    case 10: {
                        int val;
                        cout << "Enter value to insert: ";
                        cin >> val;
                        ll.insertAtStart(val);
                        break;
                    }
                    case 11: {
                        int val;
                        cout << "Enter value to insert: ";
                        cin >> val;
                        ll.insertAtEnd(val);
                        break;
                    }
                    case 12: {
                        int val, pos;
                        cout << "Enter value to insert: ";
                        cin >> val;
                        cout << "Enter position: ";
                        cin >> pos;
                        ll.insertAfter(pos, val);
                        break;
                    }
                    default:
                        cout << "Invalid Choice\n";
                }
                break;
            }

            case 2: {
                int choice2;
                cout << "To delete an element from start enter 20\nTo delete an element from end 21\nTo delete an element after a position enter 22\nChoice: ";
                cin >> choice2;
                switch(choice2) {
                    case 20:
                        ll.deleteFromStart();
                        break;
                    case 21:
                        ll.deleteFromEnd();
                        break;
                    case 22: {
                        int pos;
                        cout << "Enter position: ";
                        cin >> pos;
                        ll.deleteAfter(pos);
                        break;
                    }
                    default:
                        cout << "Invalid Choice\n";
                }
                break;
            }

            case 3: {
                int key;
                cout << "Enter the element to search: ";
                cin >> key;
                int ans = ll.search(key);
                if (ans!=-1) cout << "Position: " << ans << endl;
                break;
            }
            case 4:
                ll.display();
                break;
            
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid Choice!\n";
        }
    } while (choice!=0);
    // int ind = ll.search(15);
    // if (ind!=-1) cout << " Position: " << ind << "\n";

    // cout << "Number of Nodes: " << ll.countNodes() << endl;
    // cout << "Sum of Nodes: " << ll.sumOfNodes() << endl;

}