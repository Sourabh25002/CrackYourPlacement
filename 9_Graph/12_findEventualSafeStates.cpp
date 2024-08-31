#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool dfsRec(vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis, int ind)
  {
    vis[ind] = 1;
    pathVis[ind] = 1;

    for (auto it : adj[ind])
    {
      if (!vis[it])
      {
        if (dfsRec(adj, vis, pathVis, it) == true)
          return true;
      }
      else if (pathVis[it])
      {
        return true;
      }
    }

    pathVis[ind] = 0;
    return false;
  }

  vector<int> eventualSafeNodes(vector<vector<int>> &graph)
  {
    int n = graph.size();
    vector<int> vis(n, 0);
    vector<int> pathVis(n, 0);

    for (int i = 0; i < n; i++)
    {
      if (!vis[i])
      {
        dfsRec(graph, vis, pathVis, i);
      }
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
      if (pathVis[i] == 0)
      {
        ans.push_back(i);
      }
    }

    return ans;
  }
};

int main()
{
  Solution sol;

  vector<vector<int>> graph1 = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
  vector<vector<int>> graph2 = {{1, 2, 3, 4}, {1, 2}, {3, 4}, {0, 4}, {}};

  vector<int> result1 = sol.eventualSafeNodes(graph1);
  vector<int> result2 = sol.eventualSafeNodes(graph2);

  cout << "Safe nodes for graph1: ";
  for (int node : result1)
  {
    cout << node << " ";
  }
  cout << endl;

  cout << "Safe nodes for graph2: ";
  for (int node : result2)
  {
    cout << node << " ";
  }
  cout << endl;

  return 0;
}

/*
Time Complexity: O(V + E), where V is the number of nodes and E is the number of edges.
Space Complexity: O(V + E), for the adjacency list, visited arrays, and recursion stack.
*/
