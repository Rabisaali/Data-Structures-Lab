#include<iostream>
using namespace std;

const int V=6;
const int INF=9999;
int graph[V][V];

void addEdge(int u, int v, int w) {
    graph[u][v]=w;
    graph[v][u]=w;
}

int minDistance(int dist[], bool done[]) {
    int min = INF, index=-1;
    for(int v=0; v<V; v++) {
        if(!done[v] && dist[v]<min) {
            min=dist[v];
            index=v;
        }
    }
    return index;
}

void dijkstra(int src) {
    int dist[V];
    bool done[V];

    for(int i=0; i<V; i++) {
        dist[i]=INF;
        done[i]=false;
    }
    dist[src]=0;

    for(int count=0; count<V-1; count++) {
        int u=minDistance(dist, done);
        done[u]=true;

        for(int v=0; v<V; v++) {
            if(!done[v] && graph[u][v]!=0 && dist[u]+graph[u][v]<dist[v]) dist[v]=dist[u]+graph[u][v];
        }
    }

    cout << "Vertex Distance from " << src << endl;
    for(int i=0; i<V; i++) {
        cout << " " << i << "       " << dist[i] << endl;
    } 
}

int main () {
    addEdge(0, 1, 4);
    addEdge(0, 2, 2);
    addEdge(1, 2, 1);
    addEdge(1, 3, 5);
    addEdge(2, 3, 8);
    addEdge(2, 4, 10);
    addEdge(3, 4, 2);
    addEdge(3, 5, 6);
    addEdge(4, 5, 3);
    dijkstra(0);
}