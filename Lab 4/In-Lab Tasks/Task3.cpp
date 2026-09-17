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

};

int main() {
    SinglyLinkedList ll;
    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtStart(5);
    ll.insertAfter(1,15);
    ll.display();

    int ind = ll.search(15);
    if (ind!=-1) cout << " Position: " << ind << "\n";

    cout << "Number of Nodes: " << ll.countNodes() << endl;
    cout << "Sum of Nodes: " << ll.sumOfNodes() << endl;

}