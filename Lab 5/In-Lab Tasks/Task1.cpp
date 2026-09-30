#include<iostream>
using namespace std;
const int MAX=100;
class Stack {
    int top;

    public:
        string a[MAX];

        Stack() {
            top=-1;
        }

        bool push(string x) {
            if(top>=(MAX-1)) {
                cout << "Stack overflow\n";
                return false;
            }
            else {
                a[++top] = x;
                cout << "\"" << x << "\"" << " pushed into stack\n";
                return true;
            }
        }

        string pop() {
            if (top<0) {
                cout << "Stack is empty\n";
                return "";
            }
            else {
                string x=a[top--];
                return x;
            }
        }
        string peek() {
            if (top<0) {
                cout << "Stack is empty\n";
                return "";
            }
            else {
                string x=a[top];
                return x;
            }
        }

        bool isEmpty() {
            return (top<0);
        }

        void display() const {
            cout << "Pending tasks (top to bottom):\n";
            for(int i=top; i>=0; i--) cout << i+1 << ". " << a[i] << "\n";
            cout << endl;
        }

        void undoLastTask() {
            if(isEmpty()) {
                cout << "Stack is empty\n";
                return;
            }
            string v=pop();
            cout << "Removed: <task>" << v << "\n";
        }

        bool search(string task) const {
            int count=0;
            for(int i=top; i>=0; i--) {
                if (a[i]==task) {
                    cout << "Task found\n";
                    cout << count << " task(s) above it.\n";
                    return true;
                }
                count++;
            }
            cout << "Task not found in stack\n";
            return false;
        }
};

int main () {
    Stack s;
    int choice=0;
    do {
        cout << endl;
        cout << "1. Add Task\t2.Remove Last Task\t3.View All\t4.Search\t5.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        cout << endl;

        switch(choice) {
            case 1: {
                cout << "Enter task: ";
                string t;
                cin.ignore();
                getline(cin, t);
                s.push(t);
                break;
            }
            case 2: {
                s.undoLastTask();
                break;
            }
            case 3: {
                s.display();
                break;
            }
            case 4: {
                cout << "Enter task: ";
                string t;
                cin.ignore();
                getline(cin, t);
                s.search(t);
                break;
            }
            case 5: {
                cout << "Exiting....\n";
                break;
            }
            default:
                cout << "Invalid choice\n";
        }
    } while(choice!=5);
}
