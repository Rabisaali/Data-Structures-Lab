#include <iostream>
using namespace std;
struct Edge {
    int u, v, w;
};

const int V = 6;
const int E = 9;
int parent[V];

int findSet(int x) {
    while (parent[x] != x)
    x = parent[x];
    return x;
}

void sortEdges(Edge edges[]) {
    for (int i = 0; i<E - 1; i++)
    for (int j = 0; j<E - 1 - i; j++)
    if (edges[j].w>edges[j + 1].w) {
    Edge temp = edges[j];
    edges[j] = edges[j + 1];
    edges[j + 1] = temp;
    }
}

void kruskalMST(Edge edges[]) {
    sortEdges(edges);
    for (int i = 0; i<V; i++)
        parent[i] = i; 

    int total = 0, count = 0;
    cout<< "Edge     Weight" << endl;

    for (int i = 0; i<E && count < V - 1; i++) {
        int a = findSet(edges[i].u);
        int b = findSet(edges[i].v);
        if (a != b) { 
            cout << edges[i].u << " - " << edges[i].v;
            cout << "    " << edges[i].w << endl;
            total += edges[i].w;
            parent[a] = b; 
            count++;
        }
    }
    cout << "Total weight of MST = " << total << endl;
}

int main() {
    Edge edges[E] = {
    {0, 1, 4}, {0, 2, 2}, {1, 2, 1}, {1, 3, 5}, {2, 3, 8},
    {2, 4, 10}, {3, 4, 2}, {3, 5, 6}, {4, 5, 3}
    };
    kruskalMST(edges);
    return 0;
}