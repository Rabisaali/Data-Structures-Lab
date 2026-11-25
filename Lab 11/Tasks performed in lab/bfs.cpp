#include<iostream>
using namespace std;

const int V=6;
int adj[V][V];
bool visited[V];

int q[V];
int front=0, rear=0;

void enqueue(int x) { q[rear++] = x;}
int dequeue() { return q[front++];}
bool isEmpty() { return front==rear;}

void addEdge(int u, int v) {
    adj[u][v]=1;
    adj[v][u]=1;
}

void BFS(int start) {
    visited[start]=true;
    enqueue(start);
    while(!isEmpty()) {
        int u=dequeue();
        cout << u << " ";

        for(int v=0; v<V; v++) {
            if(adj[u][v]==1 && !visited[v]) {
                visited[v]=true;
                enqueue(v);
            }
        }
    }
}

int main () {
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 4);
    addEdge(3, 5);
    addEdge(4, 5);

    cout << "BFS starting form 0: ";
    BFS(0);
    cout << endl;
    return 0;
}