#include <iostream>
#include <stack>
#include <list>
#include <vector>
#include <string>
using namespace std;
struct Node {
    char city;
    int cost;
    Node(char c, int m = 0) {
        city = c;
        cost = m;
    }
};
class Graph {
private:
    int V;
    vector<list<Node> > adjlist;
public:
    vector<bool> visited;
    Graph(int vertex) {
        V = vertex;
        adjlist.resize(V);
        vector<bool> visited(V, false);
    }

    int index(char ch) {
        return int(ch) - 65;
    }

    void addedge(char start, Node& n) {
        int s1 = index(start);
        adjlist[s1].push_back(n);
    }

    void dfs(char start,vector <bool> &visited) {
        stack<char> st;
        int in1 = index(start);
        st.push(start);
        visited[in1] = true;
        int it;
        while (!st.empty()) {
            char curr = st.top();
            st.pop();
            cout << curr << " ";
            for (auto it = adjlist[index(curr)].begin(); it != adjlist[index(curr)].end(); ++it) {
                char next_city = (*it).city;
                int in2 = index(next_city);
                if (visited[in2] == false) {
                    st.push(next_city);
                    visited[in2] = true;
                }
            }
        }
    }
        
    bool isConnected(vector <bool> &visited) {
        // Check if all vertices are visited
        for (bool v : visited) {
            if (!v) {
                cout<<"Not connected!!!!!!!!!!!"<<endl;
                return false; // If any vertex is not visited, graph is disconnected
            }
        }
        cout<<"Connected";
        return true; // All vertices are visited, graph is connected
    }

};
int main() {
    int V;
    cout<<"Enter number of vertices: ";
    cin>>V;
    vector<bool> visited(V,false);
    Node n1('B', 500);
    Node n2('C', 200);
    Node n3('E', 180);
    Node n4('A', 134);
    Node n5('D', 899);
    Graph g1(5);
    g1.addedge('A', n1);
    g1.addedge('B', n2);
    g1.addedge('C', n3);
    g1.addedge('D', n4);
    g1.addedge('E', n5);
    g1.dfs('B',visited);
    g1.isConnected(visited);
    return 0;
}


