#include<iostream>
#include<algorithm>
using namespace std;

int find (int parent[], int vertex) {
    if (parent[vertex] != vertex) {
        parent[vertex] = find(parent, parent[vertex]);
    }
    return parent[vertex];
}

int main () {
    int vertices, edges, start, end, weight, totalweight = 0;
    cout<<"Enter the number of vertices: ";
    cin>>vertices;
    cout<<"Enter the number of edges: ";
    cin>>edges;

    int startNode[edges], endNode[edges], w[edges];
    cout<<"Enter start,end,weight: "<<endl;
    for (int i = 0; i < edges; i++) {
    cin>>start>>end>>weight;
    startNode[i] = start-1;
    endNode[i] = end-1;
    w[i] = weight;
}

for (int i = 0; i < edges-1; i++) {
    for (int j = 0; j < edges-1-i; j++) {
        if (w[j] > w[j+1]) {
            swap(w[j], w[j+1]);
            swap(startNode[j], startNode[j+1]);
            swap(endNode[j], endNode[j+1]);
        }
    }
}

    int parent[vertices];
    for (int i = 0; i < vertices; i++) {
    parent[i] = i;
    }   

    cout<<"The MST: "<<endl;
    for (int i = 0; i < edges; i++) {
    int rootStart = find (parent, startNode[i]);
    int rootEnd  = find (parent, endNode[i]);

    if (rootStart != rootEnd) {
        totalweight += w[i];
        parent[rootStart] = rootEnd;
        cout<<startNode[i]+1<<"->"<<endNode[i]+1<<" "<<w[i]<<" "<<endl;
    }

    }
    cout<<"Total Weight: "<<totalweight<<endl;
}