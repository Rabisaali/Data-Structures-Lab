#include<iostream>
using namespace std;

class MaxHeap {
    private:
        int* arr;
        int capacity;
        int size;

        int parent(int i) {return (i-1)/2;}
        int leftChild(int i) {return (2*i)+1;}
        int rightChild(int i) {return (2*i)+2;}

        void swapVal(int& a, int& b) {
            int t=a;
            a=b;
            b=t;
        }


        void heapifyUp(int i) {
            while(i>0 && arr[parent(i)]<arr[i]) {
                swapVal(arr[parent(i)], arr[i]);
                i=parent(i);
            }
        }

        void heapifyDown(int i) {
            while(true) {
                int largest=i;
                int l=leftChild(i);
                int r=rightChild(i);
                if(l<size && arr[l]>arr[largest]) largest=l;
                if(r<size && arr[r]>arr[largest]) largest=r;
                if(largest==i) break;
                swapVal(arr[i], arr[largest]);
                i=largest;
            }
        }


        public:
            MaxHeap(int cap) : capacity(cap), size(0) {arr=new int[capacity];}

            ~MaxHeap() {delete[] arr;}

            bool isEmpty() {return size==0;}

            bool isFull() {return size==capacity;}

            void insert(int value) {
                if(isFull()) {
                    cout << "heap is full\n";
                    return;
                }
                arr[size]=value;
                size++;
                heapifyUp(size-1);
            }

            int peek() {
                if(isEmpty()) {
                    cout << "heap is empty!\n";
                    return -1;
                }
                return arr[0];
            }

            int deleteMax() {
                if (isEmpty()) {
                    cout << "Heap is empty!\n";
                    return -1;
                }

                int top=arr[0];
                arr[0]=arr[size-1];
                size--;
                heapifyDown(0);
                return top;
            }

            void buildHeap(int a[], int n) {
                if(n>capacity) {
                    cout << "Array too large!\n";
                    return;
                }
                for(int i=0; i<n; i++) {
                    arr[i]=a[i];
                }

                size=n;

                for(int i=n/2-1; i>=0; i--) heapifyDown(i);
            }

            void display() {
                for(int i=0; i<size; i++) cout << arr[i] << " ";
                cout << "\n";
            }

};


int main() {
    MaxHeap h(10);
    int values[]={20, 15, 30, 10, 40};
    for(int i=0; i<5; i++) h.insert(values[i]);
    h.display();
    cout << "Peek: " << h.peek() << endl;
    cout << "Deleted: " << h.deleteMax() << endl;
    h.display();

    MaxHeap h2(10);
    int a[]={4,10,3,5,1};
    h2.buildHeap(a,5);
    h2.display();
    return 0;
}