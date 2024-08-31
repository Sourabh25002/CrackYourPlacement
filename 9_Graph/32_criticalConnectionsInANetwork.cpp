#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
  {
    vector<vector<int>> graph(n);
    vector<vector<int>> result;
    vector<int> disc(n, -1), low(n, -1), parent(n, -1);
    vector<bool> visited(n, false);
    int time = 0;

    // Build the graph
    for (auto &conn : connections)
    {
      graph[conn[0]].push_back(conn[1]);
      graph[conn[1]].push_back(conn[0]);
    }

    // DFS function
    function<void(int)> dfs = [&](int u)
    {
      visited[u] = true;
      disc[u] = low[u] = time++;

      for (int v : graph[u])
      {
        if (!visited[v])
        {
          parent[v] = u;
          dfs(v);

          low[u] = min(low[u], low[v]);

          if (low[v] > disc[u])
          {
            result.push_back({u, v});
          }
        }
        else if (v != parent[u])
        {
          low[u] = min(low[u], disc[v]);
        }
      }
    };

    // Call DFS for each component
    for (int i = 0; i < n; ++i)
    {
      if (!visited[i])
      {
        dfs(i);
      }
    }

    return result;
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<vector<int>> connections1 = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
  vector<vector<int>> result1 = sol.criticalConnections(4, connections1);
  for (const auto &edge : result1)
  {
    cout << "[" << edge[0] << "," << edge[1] << "] ";
  }
  cout << endl;

  // Example 2
  vector<vector<int>> connections2 = {{0, 1}};
  vector<vector<int>> result2 = sol.criticalConnections(2, connections2);
  for (const auto &edge : result2)
  {
    cout << "[" << edge[0] << "," << edge[1] << "] ";
  }
  cout << endl;

  return 0;
}

/*
Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges. Each vertex and edge is visited once in DFS.
Space Complexity: O(V + E), for storing the graph, disc, low, parent arrays, and the result.
*/
