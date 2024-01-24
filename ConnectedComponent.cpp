#include <bits/stdc++.h>
using namespace std;

class Graph {
	int V;
	vector<list<int>> adj;
	vector<bool>visited;
public:
	Graph(int V);
	void addEdge(int v, int w);
	void DFS(int v);
	void connectedComponents();
};

Graph::Graph(int V)
{
	this->V = V;
	adj.resize(V);
	visited.resize(V,false);
}

void Graph::addEdge(int v, int w)
{
	// Add w to v’s list.
	adj[v].push_back(w);
	adj[w].push_back(v);
}

void Graph::DFS(int v)
{
    visited[v] = true;
    cout << v << " ";
    // Recur for all the vertices adjacent to this vertex
    for (auto adjacent : adj[v]) {
            if (!visited[adjacent]) {
                DFS(adjacent);
            }
        }
}

void Graph::connectedComponents()
{
    for (int v = 0; v < V; v++) {
        if (visited[v] == false) {
            DFS(v);
            cout << "\n";
        }
    }
}



// Driver code
int main()
{
	// Create a graph given in the above diagram
    Graph g(5); // 5 vertices numbered from 0 to 4
    g.addEdge(1, 0);
    g.addEdge(2, 1);
    g.addEdge(3, 4);
    cout << "Following are connected components \n";
    g.connectedComponents();

	return 0;
}
