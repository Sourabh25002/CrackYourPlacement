#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isBipartite(int V, vector<vector<int>> &adj)
  {
    vector<int> color(V, -1); // -1 means uncolored

    for (int i = 0; i < V; ++i)
    {
      if (color[i] == -1)
      {
        if (!bfsCheck(i, adj, color))
        {
          return false;
        }
      }
    }
    return true;
  }

private:
  bool bfsCheck(int src, vector<vector<int>> &adj, vector<int> &color)
  {
    queue<int> q;
    q.push(src);
    color[src] = 0;

    while (!q.empty())
    {
      int node = q.front();
      q.pop();

      for (int neighbor : adj[node])
      {
        if (color[neighbor] == -1)
        {
          // Assign alternate color to the neighbor
          color[neighbor] = 1 - color[node];
          q.push(neighbor);
        }
        else if (color[neighbor] == color[node])
        {
          // Same color as current node means not bipartite
          return false;
        }
      }
    }
    return true;
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<vector<int>> adj1 = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
  cout << (sol.isBipartite(4, adj1) ? "1" : "0") << endl; // Output: 1

  // Example 2
  vector<vector<int>> adj2 = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
  cout << (sol.isBipartite(4, adj2) ? "1" : "0") << endl; // Output: 0

  return 0;
}

/*
Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
Space Complexity: O(V), for storing the color and the queue.
*/
