#include <iostream>
#include <cstdlib>
#include <list>
#include <queue>
using namespace std;

// A structure to represent an adjacency list node.
struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
};

// A structure to represent an adjacency list.
struct AdjList
{
    struct AdjListNode* head; // pointer to the head node of List.
};

// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of the array will be V (the number of vertices in the graph).
struct Graph
{
    int V;
    struct AdjList* array;
    void BFS(int S);
};

// A utility function to create a new adjacency list node.
struct AdjListNode* newAdjListNode(int dest)
{
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = nullptr;
    return newNode;
}

// A utility function that creates a graph of V vertices.
struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

    // Initialize each adjacency list as empty by making the head as NULL.
    for (int i = 0; i < V; ++i)
    {
        graph->array[i].head = nullptr;
    }

    return graph;
}

void Graph::BFS(int S)
{
    // Mark all the vertices as not visited.
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    // Create a queue for BFS.
    list<int> queue;

    // Mark the current node as visited and enqueue it.
    visited[S] = true;
    queue.push_back(S);

    // "i" will be used to get all adjacent vertices of a vertex.
    list<int>::iterator i;

    while (!queue.empty())
    {
        // Dequeue a vertex from the queue and print it.
        int s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued vertex s.
        // If an adjacent vertex has not been visited, mark it as visited and enqueue it.
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}
