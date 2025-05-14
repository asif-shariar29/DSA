#include <iostream>
#include <climits>
using namespace std;

int main() {
    int numNodes, numEdges, startNode;
    cout << "Enter number of nodes: ";
    cin >> numNodes;
    cout << "Enter number of edges: ";
    cin >> numEdges;
    cout << "Enter starting node: ";
    cin >> startNode;

    startNode--;

    int adjacencyMatrix[100][100] = {0};
    
    for (int i = 0; i < numEdges; ++i) {
        int sourceNode, destinationNode, edgeWeight;
        cout << "Enter source, destination, weight: ";
        cin >> sourceNode >> destinationNode >> edgeWeight;
        
        adjacencyMatrix[sourceNode - 1][destinationNode - 1] = edgeWeight;
    }

    int shortestDistance[100];
    for (int i = 0; i < numNodes; ++i)
        shortestDistance[i] = INT_MAX;
    shortestDistance[startNode] = 0;

    bool visited[100] = {false};

    for (int processedNodes = 0; processedNodes < numNodes; ++processedNodes) {
        int currentNode = -1, minDistance = INT_MAX;
        for (int i = 0; i < numNodes; ++i) {
            if (!visited[i] && shortestDistance[i] < minDistance) {
                currentNode = i;
                minDistance = shortestDistance[i];
            }
        }
        
        if (currentNode == -1) break;
        visited[currentNode] = true;

        for (int neighborNode = 0; neighborNode < numNodes; ++neighborNode) {
             if (adjacencyMatrix[currentNode][neighborNode] != 0 && 
             shortestDistance[currentNode] + adjacencyMatrix[currentNode][neighborNode] < 
             shortestDistance[neighborNode]) {
            shortestDistance[neighborNode] = shortestDistance[currentNode] + adjacencyMatrix[currentNode][neighborNode];
            }
        }
    }

    int totalWeight = 0;
    cout << "Shortest distance of nodes: ";
    for (int i = 0; i < numNodes; ++i) {
        if (shortestDistance[i] == INT_MAX) {
            cout << "-1 ";
        } else {
            cout << shortestDistance[i] << " ";
            totalWeight += shortestDistance[i];
        }
    }
    cout << endl;

    cout << "Total weight of shortest paths: " << totalWeight << endl;
    
    return 0;
}
