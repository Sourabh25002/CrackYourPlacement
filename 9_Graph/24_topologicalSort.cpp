#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> topoSort(int V, vector<vector<int>> &adj_list)
  {
    vector<int> in_degree(V, 0);
    vector<int> topo_order;
    queue<int> q;

    // Calculate in-degrees of all vertices
    for (int i = 0; i < V; ++i)
    {
      for (int neighbor : adj_list[i])
      {
        in_degree[neighbor]++;
      }
    }

    // Enqueue vertices with in-degree 0
    for (int i = 0; i < V; ++i)
    {
      if (in_degree[i] == 0)
      {
        q.push(i);
      }
    }

    // Process vertices
    while (!q.empty())
    {
      int u = q.front();
      q.pop();
      topo_order.push_back(u);

      for (int neighbor : adj_list[u])
      {
        if (--in_degree[neighbor] == 0)
        {
          q.push(neighbor);
        }
      }
    }

    return topo_order;
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<vector<int>> adj_list1 = {
      {2, 3}, // Adjacency list for vertex 0
      {3},    // Adjacency list for vertex 1
      {1},    // Adjacency list for vertex 2
      {}      // Adjacency list for vertex 3
  };
  vector<int> result1 = sol.topoSort(4, adj_list1);
  for (int i : result1)
    cout << i << " "; // Output: Topological order
  cout << endl;

  // Example 2
  vector<vector<int>> adj_list2 = {
      {2, 3}, // Adjacency list for vertex 0
      {3},    // Adjacency list for vertex 1
      {4},    // Adjacency list for vertex 2
      {4},    // Adjacency list for vertex 3
      {}      // Adjacency list for vertex 4
  };
  vector<int> result2 = sol.topoSort(5, adj_list2);
  for (int i : result2)
    cout << i << " "; // Output: Topological order
  cout << endl;

  return 0;
}

/*
Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
Space Complexity: O(V + E), for the adjacency list, in-degree array, and queue.
*/
