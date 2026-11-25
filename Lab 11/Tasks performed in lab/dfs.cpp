#include<iostream>
using namespace std;

const int V=6;
int adj[V][V];
bool visited[V];


void addEdge(int u, int v) {
    adj[u][v]=1;
    adj[v][u]=1;
}

void DFS(int u) {
    visited[u]=true;
    cout << u << " ";

    for(int v=0; v<V; v++) {
        if(adj[u][v]==1 && !visited[v]) DFS(v);
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

    cout << "DFS starting from 0: ";
    DFS(0);
    cout << endl;
}