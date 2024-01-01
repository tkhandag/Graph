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

// Driver code
int main()
{
	// Create a graph given in the above diagram
	Graph g(5);
	g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(0, 3);
  g.addEdge(2, 0);
  g.addEdge(2, 4);
  g.addEdge(2, 3);



  cout << "Following is Depth First Traversal"
            " (starting from vertex 0) \n";

    // Function call
    g.DFS(0);
    return 0;

	return 0;
}
