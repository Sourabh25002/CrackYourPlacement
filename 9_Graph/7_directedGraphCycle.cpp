#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  bool checkCycle(int node, vector<int> adj[], vector<int> &visited, vector<int> &recStack)
  {
    visited[node] = 1;
    recStack[node] = 1;

    for (auto it : adj[node])
    {
      if (!visited[it])
      {
        if (checkCycle(it, adj, visited, recStack))
          return true;
      }
      else if (recStack[it])
      {
        return true;
      }
    }

    recStack[node] = 0;
    return false;
  }

public:
  bool isCyclic(int V, vector<int> adj[])
  {
    vector<int> visited(V, 0);
    vector<int> recStack(V, 0);

    for (int i = 0; i < V; i++)
    {
      if (!visited[i])
      {
        if (checkCycle(i, adj, visited, recStack))
          return true;
      }
    }
    return false;
  }
};

int main()
{
  Solution solution;

  // Example 1
  int V1 = 4;
  vector<int> adj1[V1] = {
      {1}, {2}, {3}, {1}};
  cout << solution.isCyclic(V1, adj1) << endl; // Output: 1

  // Example 2
  int V2 = 4;
  vector<int> adj2[V2] = {
      {1}, {2}, {3}, {}};
  cout << solution.isCyclic(V2, adj2) << endl; // Output: 0

  return 0;
}

/*
Time Complexity: O(V + E)
Space Complexity: O(V)
*/
