#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isPossible(int N, int P, vector<vector<int>> &prerequisites)
  {
    // Create adjacency list and indegree vector
    vector<vector<int>> adj(N);
    vector<int> indegree(N, 0);

    // Fill adjacency list and indegree vector
    for (const auto &pre : prerequisites)
    {
      int u = pre[1], v = pre[0];
      adj[u].push_back(v);
      indegree[v]++;
    }

    // Initialize a queue for Kahn's algorithm
    queue<int> q;
    for (int i = 0; i < N; i++)
    {
      if (indegree[i] == 0)
      {
        q.push(i);
      }
    }

    int count = 0;
    while (!q.empty())
    {
      int node = q.front();
      q.pop();
      count++;

      for (int neighbor : adj[node])
      {
        if (--indegree[neighbor] == 0)
        {
          q.push(neighbor);
        }
      }
    }

    // If count equals N, all nodes were processed, so return true
    return count == N;
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<vector<int>> prerequisites1 = {{1, 0}, {2, 1}, {3, 2}};
  int N1 = 4, P1 = 3;
  // Example 2
  vector<vector<int>> prerequisites2 = {{1, 0}, {0, 1}};
  int N2 = 2, P2 = 2;

  bool result1 = sol.isPossible(N1, P1, prerequisites1);
  bool result2 = sol.isPossible(N2, P2, prerequisites2);

  cout << "Example 1: " << (result1 ? "Yes" : "No") << endl; // Output: Yes
  cout << "Example 2: " << (result2 ? "Yes" : "No") << endl; // Output: No

  return 0;
}

/*
Time Complexity: O(N + P), where N is the number of tasks and P is the number of prerequisite pairs. This is because we are traversing each task and edge once.
Space Complexity: O(N + P), due to the adjacency list and indegree vector.
*/
