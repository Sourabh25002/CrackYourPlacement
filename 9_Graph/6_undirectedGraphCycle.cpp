#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  bool checkCycle(int node, vector<int> adj[], vector<int> &visited)
  {
    queue<pair<int, int>> q; // {node, parent}
    visited[node] = 1;
    q.push({node, -1});

    while (!q.empty())
    {
      int currNode = q.front().first;
      int parent = q.front().second;
      q.pop();

      for (auto it : adj[currNode])
      {
        if (!visited[it])
        {
          visited[it] = 1;
          q.push({it, currNode});
        }
        else if (it != parent)
        {
          return true;
        }
      }
    }
    return false;
  }

public:
  bool isCycle(int V, vector<int> adj[])
  {
    vector<int> visited(V, 0);

    for (int i = 0; i < V; i++)
    {
      if (!visited[i])
      {
        if (checkCycle(i, adj, visited))
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
  int V1 = 5;
  vector<int> adj1[V1] = {
      {1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};
  cout << solution.isCycle(V1, adj1) << endl; // Output: 1

  // Example 2
  int V2 = 4;
  vector<int> adj2[V2] = {
      {}, {2}, {1, 3}, {2}};
  cout << solution.isCycle(V2, adj2) << endl; // Output: 0

  return 0;
}

/*
Time Complexity: O(V + E)
Space Complexity: O(V)
*/
