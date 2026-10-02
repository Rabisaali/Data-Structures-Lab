#include<iostream>
using namespace std;

class Stack {
    public:
        int n;
        int* arr;
        int top=-1;

        Stack(int len) {
            n=len;
            arr=new int[n];
        }

        bool isEmpty() {
            return top==-1;
        }

        void push(int x) {
            arr[++top]=x;
        }

        int pop() {
            if (isEmpty()) {
                cout << "Stack is empty\n";
                return -1;
            }
            return arr[top--];
        }

        ~Stack() {
            delete[] arr;
        }
};

class Queue {
    public:
        Stack stackIn;
        Stack stackOut;

        Queue(int n) : stackIn(n), stackOut(n) {}

        void enqueue(int x) {
            stackIn.push(x);
        }

        int dequeue() {
            if (stackOut.isEmpty()) {
                while (!stackIn.isEmpty()) {
                    stackOut.push(stackIn.pop());
                }
            }

            return stackOut.pop();
        }
};

int main() {
    Queue q(10);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << q.dequeue() << endl;

    q.enqueue(4);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    return 0;
}