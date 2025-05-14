#include<iostream>
#include<queue>
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
queue <int> q;
q.push(start);
visited[start] = true;

cout<<"BFS traversal: ";
while (!q.empty()) {
    int node = q.front();
    q.pop();
    cout<<node<<" ";
    for (int i = 1; i <= nodes; ++i) {
        if (graph[node][i] == 1 && !visited[i]) {
            visited[i] = true;
            q.push(i);
        }
    }

}


cout<<endl;


}