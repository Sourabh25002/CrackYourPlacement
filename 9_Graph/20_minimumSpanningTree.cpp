#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int spanningTree(int V, vector<vector<pair<int, int>>> &adj)
  {
    // Priority queue to select the edge with the minimum weight
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> key(V, INT_MAX);  // To store the minimum weight edge for each vertex
    vector<bool> inMST(V, false); // To check if the vertex is included in MST
    int sum = 0;                  // To store the sum of weights of MST edges

    // Start from the first vertex (0)
    pq.push({0, 0});
    key[0] = 0;

    while (!pq.empty())
    {
      int u = pq.top().second;     // Get the vertex with the minimum edge weight
      int weight = pq.top().first; // Get the weight of the edge
      pq.pop();

      // If the vertex is already included in MST, skip it
      if (inMST[u])
        continue;
      inMST[u] = true;
      sum += weight; // Add the weight to the total sum

      // Update the priority queue with the new edges
      for (const auto &edge : adj[u])
      {
        int v = edge.first;
        int w = edge.second;
        if (!inMST[v] && w < key[v])
        {
          key[v] = w;
          pq.push({w, v});
        }
      }
    }

    return sum;
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<vector<pair<int, int>>> adj1(3);
  adj1[0].emplace_back(1, 5);
  adj1[1].emplace_back(0, 5);
  adj1[1].emplace_back(2, 3);
  adj1[2].emplace_back(1, 3);
  adj1[0].emplace_back(2, 1);
  adj1[2].emplace_back(0, 1);

  // Example 2
  vector<vector<pair<int, int>>> adj2(2);
  adj2[0].emplace_back(1, 5);
  adj2[1].emplace_back(0, 5);

  cout << "Example 1: " << sol.spanningTree(3, adj1) << endl; // Output: 4
  cout << "Example 2: " << sol.spanningTree(2, adj2) << endl; // Output: 5

  return 0;
}

/*
Time Complexity: O(E log V), where E is the number of edges and V is the number of vertices. This is due to the priority queue operations.
Space Complexity: O(V^2), due to the adjacency list representation.
*/
