#include<iostream>
#include<stack>
using namespace std;


int main() {

    int nodes, edges;
    cout<<"Enter the number of Nodes: ";
    cin>>nodes;
    cout<<"Enter the number of Edges: ";
    cin>>edges;

    int graph[100][100] = {0};

    cout<<"enter edges: ";
    for (int i = 0; i < edges; ++i) {
    int u, v;
    cin>>u>>v;
    graph[u][v] = 1;
    graph[v][u] = 1;
    }

    int start;
    cout<<"Enter starting node: ";
    cin>>start;

    bool visited[100] = {false};
    stack <int> s;
    s.push(start);
    visited[start] = true;

    cout<<"DFS traversal: ";
    while (!s.empty()) {
    int node = s.top();
    s.pop();
    cout<<node<<" ";
    for (int i = 1; i <= nodes; ++i) {
        if (graph[node][i] == 1 && !visited[i]) {
            visited[i] = true;
            s.push(i);
        }
    }

}

cout<<endl;

}