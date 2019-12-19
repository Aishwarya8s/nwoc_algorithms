// C++ program to find the longest distance between any 2 vertices of the graph
// We are a here creating an undirected graph and then proceed with programming the 
//code for finding the longest path between any 2 given vertices

#include<iostream>
#include<bits/stdc++.h> 
using namespace std; 

// visited[] array to make nodes visited 
// src is starting node of the undirected graph for DFS traversal 
// prev_len is sum of path lengths till current node 
// max_len is pointer which stores the longest path 
// of cable value after DFS traversal 

void DFS(vector< pair<int,int> > graph[], int src, 
		int prev_len, int *max_len, 
		vector <bool> &visited) 
{ 
	// Mark the src node visited in the undirected graph
	visited[src] = 1; 

	// curr_len is for path length from src 
	// node or vertex to its adjacent vertex
	int curr_len = 0; 

	// Adjacent is pair type which stores 
	// destination node and path length 
	pair < int, int > adjacent; 

	// Traverse all adjacent nodes
	for (int i=0; i<graph[src].size(); i++) 
	{ 
		// Adjacent element 
		adjacent = graph[src][i]; 

		// check to see If node is not visited 
		if (!visited[adjacent.first]) 
		{ 
			// Total length of cable from src vertex
			// to its adjacent 
			curr_len = prev_len + adjacent.second; 

			// Call DFS for adjacent vertex
			DFS(graph, adjacent.first, curr_len, 
				max_len, visited); 
		} 

		// If total path length till now is greater than 
		// previous length then update it and move ahead 
		if ((*max_len) < curr_len) 
			*max_len = curr_len; 

		// make curr_len = 0 for next adjacent 
		curr_len = 0; 
	} 
} 

// n is number of verices or nodes in graph 
int longestCable(vector<pair<int,int> > graph[], 
										int n) 
{ 
	// longest path between any 2 connected vertices 
	//of the undirected graph
	int max_len = INT_MIN; 

	// call DFS methof on each vertex to find longest 
	//path between the connected vertices 
	for (int i=1; i<=n; i++) 
	{ 
		// initialize visited array with 0 
		vector< bool > visited(n+1, false); 

		// Call DFS for src vertex i 
		DFS(graph, i, 0, &max_len, visited); 
	} return max_len; 
} 


int main() 
{ 
	// here n id the number of vertices of the undirected graph 
	int n = 6; 

	vector< pair<int,int> > graph[n+1]; 

	// Now, let's create the undirected graph with given number of vertices
	
	// first edge 
	graph[1].push_back(make_pair(2, 3)); 
	graph[2].push_back(make_pair(1, 3)); 

	// second edge 
	graph[2].push_back(make_pair(3, 4)); 
	graph[3].push_back(make_pair(2, 4)); 

	// third edge 
	graph[2].push_back(make_pair(6, 2)); 
	graph[6].push_back(make_pair(2, 2)); 

	// fourth edge 
	graph[4].push_back(make_pair(6, 6)); 
	graph[6].push_back(make_pair(4, 6)); 

	// fifth edge 
	graph[5].push_back(make_pair(6, 5)); 
	graph[6].push_back(make_pair(5, 5)); 

	cout << "Longest path between the 2 provided vertices of the undirected graph = "
		<< longestCable(graph, n); 

	return 0; 
} 

/* sample output will be as follows:
given the number of nodes in the undirected graph is 6=>

Longest path between the 2 provided vertices of the undirected graph = 12
*/
