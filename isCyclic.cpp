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
	bool isCyclic();
	bool isCyclicUtil(int v, bool visited[], int parent);
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

bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{

    // Mark the current node as visited
    visited[v] = true;

    for (int value : adj[v]) {

        if (!visited[value]) {
            if (isCyclicUtil(value, visited, v))
                return true;
        }
        else if(value!=parent){
           return true;
        }
    }
    return false;
}


bool Graph::isCyclic()
{
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;


    for (int u = 0; u < V; u++) {

        if (!visited[u])
            if (isCyclicUtil(u, visited, -1))
                return true;
    }

    return false;
}



// Driver code
int main()
{
	// Create a graph given in the above diagram
    Graph g1(5); // 5 vertices numbered from 0 to 4
    g1.addEdge(1, 0);
    //g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isCyclic() ? cout << "Graph contains cycle\n"
                  : cout << "Graph doesn't contain cycle\n";

	  return 0;
}
