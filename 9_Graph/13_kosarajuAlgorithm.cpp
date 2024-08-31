#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void dfs1(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &Stack)
  {
    visited[node] = true;
    for (int neighbor : adj[node])
    {
      if (!visited[neighbor])
      {
        dfs1(neighbor, adj, visited, Stack);
      }
    }
    Stack.push(node);
  }

  void dfs2(int node, vector<vector<int>> &adjRev, vector<bool> &visited)
  {
    visited[node] = true;
    for (int neighbor : adjRev[node])
    {
      if (!visited[neighbor])
      {
        dfs2(neighbor, adjRev, visited);
      }
    }
  }

  int kosaraju(int V, vector<vector<int>> &adj)
  {
    stack<int> Stack;
    vector<bool> visited(V, false);

    // Step 1: Fill nodes in stack according to their finishing times
    for (int i = 0; i < V; i++)
    {
      if (!visited[i])
      {
        dfs1(i, adj, visited, Stack);
      }
    }

    // Step 2: Reverse the graph
    vector<vector<int>> adjRev(V);
    for (int i = 0; i < V; i++)
    {
      for (int neighbor : adj[i])
      {
        adjRev[neighbor].push_back(i);
      }
    }

    // Step 3: Process all vertices in order defined by Stack
    fill(visited.begin(), visited.end(), false);
    int sccCount = 0;

    while (!Stack.empty())
    {
      int node = Stack.top();
      Stack.pop();

      if (!visited[node])
      {
        dfs2(node, adjRev, visited);
        sccCount++;
      }
    }

    return sccCount;
  }
};

int main()
{
  Solution sol;

  int V1 = 5;
  vector<vector<int>> adj1 = {
      {1},    // 0 -> 1
      {2},    // 1 -> 2
      {0, 3}, // 2 -> 0, 2 -> 3
      {4},    // 3 -> 4
      {}      // 4 -> nothing
  };

  int V2 = 4;
  vector<vector<int>> adj2 = {
      {1}, // 0 -> 1
      {2}, // 1 -> 2
      {3}, // 2 -> 3
      {0}  // 3 -> 0
  };

  int result1 = sol.kosaraju(V1, adj1);
  int result2 = sol.kosaraju(V2, adj2);

  cout << "Number of SCCs in graph1: " << result1 << endl;
  cout << "Number of SCCs in graph2: " << result2 << endl;

  return 0;
}

/*
Time Complexity: O(V + E), where V is the number of nodes and E is the number of edges.
Space Complexity: O(V + E), for the adjacency lists and recursion stack.
*/
