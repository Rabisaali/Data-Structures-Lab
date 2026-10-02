#include<iostream>
using namespace std;

/*
In a linear queue, once rear reaches N-1, the queue is considered full even
if there are empty spaces at the front because those spaces cannot be reused.
A circular queue solves this by wrapping rear back to index 0 using modulo (%),
allowing the freed spaces at the front to be reused.
*/

class Queue {
    private:
        int* arr;
        int N;
        int rear;
        int front;
    public:
        Queue() {
            N=5;
            arr = new int[N];
            rear=-1;
            front=-1;
        }

        bool isFull() {
            if(rear == N-1) return true;
            else return false;
        }

        bool isEmpty() {
            if(front==-1 && rear==-1) return true;
            else return false;
        }

        void enqueue(int val) {
            if (isFull()) {
                cout << "Queue is full, cannot add " << val << endl;
                return;
            }
            else if (isEmpty()) rear=front=0;
            else {
                rear += 1;
            }
            arr[rear]=val;
            cout << val << " added to the queue\n";
        }

        void dequeue() {
            int x=-1;
            if(isEmpty()) {
                cout << "Queue is empty\n";
                return;
            }
            else if (front==rear) {
                x=arr[front];
                front=rear=-1;
            }
            else {
                x=arr[front];
                front+=1;
            }
            cout << x << " removed from the queue\n";
        }

        ~Queue() {
            delete[] arr;
        }
    
};
int main () {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.enqueue(60);
    q.enqueue(70);
    
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
}