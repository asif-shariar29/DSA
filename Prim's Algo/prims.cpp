#include <iostream>
#include <climits>
using namespace std;

int main() {
    int vertices;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    int graph[vertices][vertices]; 
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < vertices; ++i)
        for (int j = 0; j < vertices; ++j)
            cin >> graph[i][j];

    int key[vertices], parent[vertices], inMST[vertices];
    int totalWeight = 0;

    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX; 
        parent[i] = -1;   
        inMST[i] = 0;     
    }

    key[0] = 0; 

    for (int count = 0; count < vertices - 1; count++) {
        int minKey = INT_MAX, u;

        for (int v = 0; v < vertices; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        inMST[u] = 1; 

        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Edge   Weight\n";
    for (int i = 1; i < vertices; i++) {
        cout << parent[i] << " - " << i << "   " << graph[i][parent[i]] << endl;
        totalWeight += graph[i][parent[i]];
    }

    cout << "Total weight of MST: " << totalWeight << endl;

    return 0;
}