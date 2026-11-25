#include <iostream>
using namespace std;

const int V = 6;
const int INF = 9999;
int graph[V][V];

void addEdge(int u, int v, int w) {
    graph[u][v] = w;
    graph[v][u] = w;
}

void primMST() {
    int key[V]; 
    int parent[V]; 
    bool inMST[V];
    for (int i = 0; i<V; i++) {
        key[i] = INF;
        inMST[i] = false;
    }
    key[0] = 0; 
    parent[0] = -1;

    for (int count = 0; count <V - 1; count++) {
        int u=-1;
        for(int v=0; v<V; v++) {
            if(!inMST[v] && (u==-1 || key[v] < key[u])) u=v;
        }

        inMST[u]=true;

        for(int v=0; v<V; v++) {
            if(graph[u][v]!=0 && !inMST[v] && graph[u][v]<key[v]) {
                key[v]=graph[u][v];
                parent[v]=u;
            }
        }
    }

    int total=0;
    cout << "Edge     Weight" << endl;
    for(int i=1; i<V; i++) {
        cout << parent[i] << " - " << i << "        " << graph[i][parent[i]] << endl;
        total+=graph[i][parent[i]];
    }

    cout << "Total weight of MST = " << total << endl;

}

int main() {
    addEdge(0, 1, 4);
    addEdge(0, 2, 2);
    addEdge(1, 2, 1);
    addEdge(1, 3, 5);
    addEdge(2, 3, 8);
    addEdge(2, 4, 10);
    addEdge(3, 4, 2);
    addEdge(3, 5, 6);
    addEdge(4, 5, 3);
    primMST();
    return 0;
}