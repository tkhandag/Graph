#include <bits/stdc++.h>
using namespace std;

class Graph {
	int V;
	vector<list<int>> adj;
public:
	Graph(int V);
	void addEdge(int v, int w);
	void BFS(int s);
};

Graph::Graph(int V)
{
	this->V = V;
	adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
	// Add w to v’s list.
	adj[v].push_back(w);
}

void Graph::BFS(int s)
{
	vector<bool>visited;
	visited.resize(V,false);
	queue<int>q;
	visited[s]=true;
	q.push(s);
	while(!q.empty()){
	  s = q.front();
	  cout<<s<<" ";
	  q.pop();
	  for(auto adjacent : adj[s]){
	    if(!visited[adjacent]){
	      visited[adjacent]=true;
	      q.push(adjacent);
	    }
	  }
	}
}

// Driver code
int main()
{
	// Create a graph given in the above diagram
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n";
	g.BFS(2);

	return 0;
}
