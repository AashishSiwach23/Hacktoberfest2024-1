#include <iostream>
#include <list>
#include <queue>
using namespace std;

// Class to represent a graph
class Graph {
    int V; // Number of vertices
    list<int>* adj; // Pointer to an array containing adjacency lists

public:
    // Constructor
    Graph(int v) {
        V = v;
        adj = new list<int>[v];
    }

    // Function to add an edge to the graph
    void addEdge(int v, int w) {
        adj[v].push_back(w); // Add w to v’s list
    }

    // BFS traversal function
    void BFS(int s) {
        // Mark all vertices as not visited
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++) {
            visited[i] = false;
        }

        // Create a queue for BFS
        queue<int> q;

        // Mark the current node as visited and enqueue it
        visited[s] = true;
        q.push(s);

        // Loop to traverse the graph
        while (!q.empty()) {
            // Dequeue a vertex from queue and print it
            s = q.front();
            cout << s << " ";
            q.pop();

            // Get all adjacent vertices of the dequeued vertex s
            // If an adjacent vertex has not been visited, mark it visited and enqueue it
            for (auto adjVertex : adj[s]) {
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    q.push(adjVertex);
                }
            }
        }

        // Free the allocated memory
        delete[] visited;
    }
};

// Driver program to test the BFS function
int main() {
    // Create a graph with 6 vertices
    Graph g(6);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    cout << "BFS starting from vertex 0:" << endl;
    g.BFS(0); // Start BFS from vertex 0

    return 0;
}
