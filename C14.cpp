#include <iostream>
#include <vector>
#include <list>
#include <utility>
using namespace std;
class Graph {
public:
    int V; // Number of vertices (cities)
    list<pair<int, int> > *adj; // Array of adjacency lists, where pair<int, int> is (destination, weight)

    Graph(int V) {
        this->V = V;
        adj = new list<pair<int, int> >[V];
    }
    ~Graph() {
        delete[] adj;
    }
    void addEdge(int u, int v, int weight) {
        adj[u].push_back(make_pair(v, weight)); // Add edge from u to v with weight
        adj[v].push_back(make_pair(u, weight)); // For undirected graph, also add edge from v to u
    }
    void DFSUtil(int v, bool visited[]) {
        visited[v] = true;
        for (auto& neighbor : adj[v]) {
            int u = neighbor.first;
            if (!visited[u]) {
                DFSUtil(u, visited);
            }
        }
    }
    bool isConnected() {
        // Mark all vertices as not visited
        bool visited[V] = {false};
        
        // Start DFS from the first non-isolated vertex
        int startVertex = -1;
        for (int i = 0; i < V; i++) {
            if (!adj[i].empty()) {
                startVertex = i;
                break;
            }
        }
        
        if (startVertex == -1) {
            // All vertices are isolated
            return true;
        }
        DFSUtil(startVertex, visited);
        for (int i = 0; i < V; i++) {
            if (!visited[i] && !adj[i].empty()) {
                return false; // A vertex was not visited, so the graph is not connected
            }
        }
        return true;
    }
};
int main() {
    int V = 5; // Number of vertices (cities)
    Graph g(V);
    g.addEdge(0, 1, 10); // Flight path from city 0 to city 1 with weight 10
    g.addEdge(0, 2, 15); // Flight path from city 0 to city 2 with weight 15
    g.addEdge(1, 2, 5); // Flight path from city 1 to city 2 with weight 5
    g.addEdge(2, 3, 7); // Flight path from city 2 to city 3 with weight 7
    g.addEdge(3, 4, 3); // Flight path from city 3 to city 4 with weight 3
    cout << "\n";
    if (g.isConnected()) {
        cout << "The graph is connected.\n";
    } else {
        cout << "The graph is not connected.\n";
    }
    return 0;
}

