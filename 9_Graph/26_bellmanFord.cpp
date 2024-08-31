#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool detectNegativeCycle(int V, vector<vector<int>> &edges)
  {
    // Initialize distance array
    vector<int> dist(V, INT_MAX);
    dist[0] = 0; // Start from vertex 0

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; ++i)
    {
      for (const auto &edge : edges)
      {
        int u = edge[0], v = edge[1], weight = edge[2];
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
          dist[v] = dist[u] + weight;
        }
      }
    }

    // Check for negative-weight cycles
    for (const auto &edge : edges)
    {
      int u = edge[0], v = edge[1], weight = edge[2];
      if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
      {
        return true; // Negative cycle detected
      }
    }

    return false; // No negative cycle
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<vector<int>> edges1 = {{0, 1, 1}, {1, 2, -1}, {2, 3, -1}, {3, 1, -1}};
  cout << (sol.detectNegativeCycle(4, edges1) ? "Yes" : "No") << endl; // Output: Yes

  // Example 2
  vector<vector<int>> edges2 = {{0, 1, 1}, {1, 2, 1}, {2, 3, 1}, {3, 4, 1}};
  cout << (sol.detectNegativeCycle(5, edges2) ? "Yes" : "No") << endl; // Output: No

  return 0;
}

/*
Time Complexity: O(V * E), where V is the number of vertices and E is the number of edges.
Space Complexity: O(V), where V is the number of vertices.
*/
