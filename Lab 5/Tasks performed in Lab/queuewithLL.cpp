#include<iostream>
using namespace std; 

class Node {
    public:
    int val;
    Node* next;

    Node(int v) {
        val=v;
        next=NULL;
    }
};
class Queue {
    public:
        Node* rear;
        Node* front;
        Queue () {
            rear=NULL;
            front=NULL;
        }

        void enqueue(int v) {
            Node* temp=new Node(v);
            if (rear==NULL) {
                front=temp;
                rear=temp;
            }
            else {
                rear->next=temp;
                rear=temp;
            }
        }

        int dequeue() {
            if (front==NULL) {
                cout << "stack is empty\n";
                return -1;
            }
            else {
                Node* temp=front;
                // while(temp->next!=tail) {
                //     temp=temp->next;
                // }
                int value=front->val;
                front=front->next;
                delete temp;
                return value;
            }
        }

        void peek() {
            if (front==NULL) {
                cout << "stack is empty\n";
                return;
            }
            else {
                cout << front->val;
            }
        }


};

int main () {
    Queue s;
    s.enqueue(0);
    s.enqueue(1);
    s.enqueue(9);
    s.enqueue(5);
    s.enqueue(6);

    s.peek();
    cout << "\n";
    cout << s.dequeue() << " " << s.dequeue() << " " << s.dequeue() << " " << s.dequeue() << " " << s.dequeue() << "\n";   
    s.peek();
    //cout << s.pop() << "\n";
}

