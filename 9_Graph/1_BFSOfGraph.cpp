#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> bfsOfGraph(int V, vector<int> adj[])
  {
    vector<int> bfs;
    vector<bool> visited(V, false);
    queue<int> q;

    // Start BFS from vertex 0
    visited[0] = true;
    q.push(0);

    while (!q.empty())
    {
      int node = q.front();
      q.pop();
      bfs.push_back(node);

      // Traverse all adjacent nodes of the current node
      for (int neighbor : adj[node])
      {
        if (!visited[neighbor])
        {
          visited[neighbor] = true;
          q.push(neighbor);
        }
      }
    }

    return bfs;
  }
};

int main()
{
  Solution solution;

  // Example 1
  int V1 = 5, E1 = 4;
  vector<int> adj1[5] = {{1, 2, 3}, {}, {4}, {}, {}};

  vector<int> result1 = solution.bfsOfGraph(V1, adj1);
  for (int i : result1)
  {
    cout << i << " ";
  }
  cout << endl;

  // Example 2
  int V2 = 3, E2 = 2;
  vector<int> adj2[3] = {{1, 2}, {}, {}};

  vector<int> result2 = solution.bfsOfGraph(V2, adj2);
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
- O(V) for the visited array and the queue used in BFS.
*/
