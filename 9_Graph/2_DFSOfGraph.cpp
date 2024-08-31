#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void dfs(int node, vector<int> adj[], vector<bool> &visited, vector<int> &dfsResult)
  {
    visited[node] = true;
    dfsResult.push_back(node);

    // Traverse all adjacent nodes of the current node
    for (int neighbor : adj[node])
    {
      if (!visited[neighbor])
      {
        dfs(neighbor, adj, visited, dfsResult);
      }
    }
  }

  vector<int> dfsOfGraph(int V, vector<int> adj[])
  {
    vector<int> dfsResult;
    vector<bool> visited(V, false);

    // Start DFS from vertex 0
    dfs(0, adj, visited, dfsResult);

    return dfsResult;
  }
};

int main()
{
  Solution solution;

  // Example 1
  int V1 = 5;
  vector<int> adj1[5] = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};

  vector<int> result1 = solution.dfsOfGraph(V1, adj1);
  for (int i : result1)
  {
    cout << i << " ";
  }
  cout << endl;

  // Example 2
  int V2 = 4;
  vector<int> adj2[4] = {{1, 3}, {2, 0}, {1}, {0}};

  vector<int> result2 = solution.dfsOfGraph(V2, adj2);
  for (int i : result2)
  {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}

/*
Time Complexity:
- O(V + E), where V is the number of vertices and E is the number of edges.

Space Complexity:
- O(V) for the visited array and the recursion stack used in DFS.
*/
