#include<iostream>
using namespace std;

class Queue {
    public:
        string* arr;
        int N;
        int rear;
        int front;
    
        Queue(int n) {
            N=n;
            arr = new string[n];
            rear=-1;
            front=-1;
        }

        bool isFull() {
            if((rear+1)%N == front) return true;
            else return false;
        }

        bool isEmpty() {
            if(front==-1 && rear==-1) return true;
            else return false;
        }

        void enqueue(string name) {
            if (isFull()) {
                cout << "Queue is full, cannot add " << name << endl;
                return;
            }
            else if (isEmpty()) rear=front=0;
            else {
                rear = (rear+1)%N;
            }
            arr[rear]=name;
            cout << name << " added to the queue\n";
        }

        string dequeue() {
            string x="";
            if(isEmpty()) {
                cout << "Queue is empty\n";
                return x;
            }
            else if (front==rear) {
                x=arr[front];
                front=rear=-1;

            }
            else {
                x=arr[front];
                front=(front+1)%N;
            }
            return x;
        }

        void displayQueue() {
            if (front==-1) {
                cout << "Queue is empty\n";
                return;
            }

            int i = front;

            while (true) {
                cout << arr[i] << " ";

                if (i==rear) break;
                i=(i+1)%N;
            }
            cout << endl;
        }

        ~Queue() {
            delete[] arr;
        }
    
};
int main () {
    int n;
    cout << "Enter N: ";
    cin >> n;
    Queue q(n);

    int choice;
    do {
        cout << "1. Add Customer\t2. Serve Customer\t3.View Queue\t4.Exit\n";
        cin >> choice;

        switch(choice) {
            case 1: {
                cout << "Add Customer: ";
                string s;
                cin >> s;
                q.enqueue(s);
                break;
            }

            case 2: {
                cout << "Serve Customer: ";
                string s=q.dequeue();
                if (s!="") cout << "Serving " << s << endl;
                break;
            }

            case 3: {
                cout << "View Queue: ";
                q.displayQueue();
                break;
            }

            case 4: {
                cout << "Exiting.....\n";
                break;
            }

            default:
                cout << "Invalid choice\n";

        }
    } while (choice!=4);
}