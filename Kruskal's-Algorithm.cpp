#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph {
    int V, E;  // V is the number of vertices, E is the number of edges

    // A graph is represented as an array of edges
    vector<Edge> edges;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// A utility function to find the subset of an element `i` (uses path compression)
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// A utility function to do union of two subsets `x` and `y` (uses union by rank)
void Union(Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    // Attach smaller rank tree under root of higher rank tree
    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Compare function to sort edges according to their weights
bool compare(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

// Function to perform Kruskal's algorithm
void KruskalMST(Graph& graph) {
    int V = graph.V;
    vector<Edge> result;  // Store the resulting MST

    // Step 1: Sort all the edges in non-decreasing order of their weight
    sort(graph.edges.begin(), graph.edges.end(), compare);

    // Allocate memory for creating V subsets
    Subset* subsets = new Subset[V];

    // Create V subsets with single elements
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Iterate through all sorted edges
    for (Edge& e : graph.edges) {
        int x = find(subsets, e.src);
        int y = find(subsets, e.dest);

        // If including this edge does not cause a cycle, include it in the result
        if (x != y) {
            result.push_back(e);
            Union(subsets, x, y);
        }

        // Stop when we have V-1 edges in the result (since a MST has V-1 edges)
        if (result.size() == V - 1)
            break;
    }

    // Print the resulting MST
    cout << "Edge \tWeight\n";
    for (Edge& e : result)
        cout << e.src << " - " << e.dest << "\t" << e.weight << endl;

    delete[] subsets;
}

int main() {
    int V = 4, E = 5;  // Number of vertices and edges in the graph
    Graph graph;
    graph.V = V;
    graph.E = E;

    // Add edges to the graph
    graph.edges.push_back({0, 1, 10});
    graph.edges.push_back({0, 2, 6});
    graph.edges.push_back({0, 3, 5});
    graph.edges.push_back({1, 3, 15});
    graph.edges.push_back({2, 3, 4});

    // Perform Kruskal's algorithm to find MST
    KruskalMST(graph);

    return 0;
}
