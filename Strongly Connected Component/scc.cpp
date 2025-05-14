#include <iostream>
#include <stack>
using namespace std;

    const int MAX = 100;
    int adj[MAX][MAX];   
    int adjT[MAX][MAX]; 
    int visited[MAX];   
    stack<int> st;     
    
    int n, e;           
    void dfs(int u) {
    visited[u] = 1;
    for (int v = 0; v < n; v++) {
        if (adj[u][v] && !visited[v]) { 
            dfs(v); 
        }
    }
    st.push(u); 
}

void dfsTranspose(int u) {
    visited[u] = 1;
    cout << u << " "; 
    for (int v = 0; v < n; v++) {
        if (adjT[u][v] && !visited[v]) { 
            dfsTranspose(v); 
        }
    }
}

int main() {
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1; 
        adjT[v][u] = 1; 
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) { 
            dfs(i);
        }
    }
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    int scc = 0; 
    cout << "Strongly Connected Components:" << endl;
    while (!st.empty()) {
        int u = st.top(); 
        st.pop();
        if (!visited[u]) { 
            dfsTranspose(u); 
            scc++; 
            cout << endl; 
        }
    }
    
    cout << "Number of SCCs: " << scc << endl;
    return 0;
}
