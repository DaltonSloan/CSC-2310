#include <iostream>

using namespace std;

class Graph {
public:
    int V; // Number of vertices
    int **adj; // Adjacency list (2D array)

    // Constructor to initialize the graph with 'V' vertices
    Graph(int V) {
        this->V = V;
        adj = new int*[V];
        for (int i = 0; i < V; ++i) {
            adj[i] = new int[V];
            for (int j = 0; j < V; ++j) {
                adj[i][j] = 0;
            }
        }
    }

    // Function to add an edge to the graph
    void addEdge(int src, int dest) {
        adj[src][dest] = 1;
        adj[dest][src] = 1; // For an undirected graph
    }

    // Recursive function for DFS traversal
    void DFSUtil(int source, bool visited[]) {
        visited[source] = true;
        cout << source << " ";

        for (int neighbor = 0; neighbor < V; ++neighbor) {
            if (adj[source][neighbor] && !visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    // DFS traversal of the graph starting from the source node
    void DFS(int source) {
        bool *visited = new bool[V];
        for (int i = 0; i < V; ++i) {
            visited[i] = false;
        }

        cout << "Depth-First Traversal starting from node " << source << ": ";
        DFSUtil(source, visited);
        cout << endl;

        delete[] visited;
    }

    // BFS traversal of the graph starting from the source node
    void BFS(int source) {
        bool *visited = new bool[V];
        for (int i = 0; i < V; ++i) {
            visited[i] = false;
        }

        int *customQueue = new int[V];
        int front = 0, rear = 0;

        visited[source] = true;
        customQueue[rear++] = source;

        cout << "Breadth-First Traversal starting from node " << source << ": ";

        while (front != rear) {
            int current = customQueue[front++];
            cout << current << " ";

            for (int neighbor = 0; neighbor < V; ++neighbor) {
                if (adj[current][neighbor] && !visited[neighbor]) {
                    visited[neighbor] = true;
                    customQueue[rear++] = neighbor;
                }
            }
        }
        cout << endl;

        delete[] visited;
        delete[] customQueue;
    }

    ~Graph() {
        for (int i = 0; i < V; ++i) {
            delete[] adj[i];
        }
        delete[] adj;
    }
};

int main() {
    int V = 6; // Number of nodes
    Graph graph(V);

    // Add edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);

    int source = 0; // Starting node for both DFS and BFS
    graph.DFS(source);
    graph.BFS(source);

    return 0;
}
