#include<iostream>
#include<cstring>
#define MAX 100
using namespace std;

int numNodes, adj[MAX][MAX], parent[MAX], low[MAX], dis[MAX], timecount;
bool isArticulation[MAX], visited[MAX];

void DFS (int node) {
    visited[node] = true;
    dis[node] = low[node] = ++timecount;
    int child = 0;

    for (int i = 0; i < numNodes; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                parent[i] = node;
                child++;
                DFS(i);
                low[node] = min(low[node], low[i]);

                if ((parent[node] == -1 && child > 1) || (parent[node] != -1 && low[i] >= dis[node])) {
                    isArticulation[node] = true;
                }
            }
            else if (i != parent[node]) {
                low[node] = min (low[node], dis[i]);
            }
        }
    }
}

int main() {
    int numEdges, node1, node2;
    cout<<"Enter the number of Nodes: ";
    cin >> numNodes; 
    cout<<"Enter the number of Edges: ";
    cin>> numEdges;
    memset(adj, 0, sizeof(adj));
    memset(parent, -1, sizeof(parent));

    while (numEdges--) {
        cout<<"Enter edges: ";
        cin >> node1 >> node2;
        adj[node1][node2] = adj[node2][node1] = 1;
    }

    for (int i = 0; i < numNodes; i++) if (!visited[i]) DFS(i);
    for (int i = 0; i < numNodes; i++) if (isArticulation[i]) cout <<"Articulation point: "<< i << " ";
}