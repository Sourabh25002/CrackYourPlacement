#include <bits/stdc++.h>
using namespace std;

class DisjointDS
{
public:
  vector<int> parent; // Stores the parent of ith node
  vector<int> rank;   // Stores the rank of ith node

  DisjointDS(int n)
  { // n is the number of nodes in the graph
    parent.resize(n + 1);
    rank.resize(n + 1, 0); // Initialize the rank of every node as 0

    for (int i = 0; i <= n; i++)
    { // Initialize the parent of node i as i itself
      parent[i] = i;
    }
  }

  bool Union(int u, int v)
  { // Union by Rank. Returns TRUE if UNION can be performed without introducing any cycle
    // Get the representatives of the vertices
    int ru = Find(u);
    int rv = Find(v);

    // An edge between them will create a loop since they both belong to the same set/component
    if (ru == rv)
      return false;

    if (rank[ru] > rank[rv])
    {
      parent[rv] = ru;
    }
    else if (rank[rv] > rank[ru])
    {
      parent[ru] = rv;
    }
    else
    {
      parent[rv] = ru;
      rank[ru]++;
    }
    return true;
  }

  int Find(int node)
  { // Returns the representative of this node
    if (parent[node] != node)
    {
      parent[node] = Find(parent[node]); // Path compression
    }
    return parent[node];
  }
};

class Solution
{
public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges)
  {
    int numOfNodes = edges.size();
    DisjointDS dds(numOfNodes);

    for (auto &edge : edges)
    {
      int u = edge[0];
      int v = edge[1];

      if (!dds.Union(u, v))
      {
        return {u, v}; // If we cannot unionize these 2 edges, adding them will create a cycle
      }
    }

    return {-1, -1};
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> edges1 = {{1, 2}, {1, 3}, {2, 3}};
  vector<vector<int>> edges2 = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};

  vector<int> result1 = sol.findRedundantConnection(edges1);
  vector<int> result2 = sol.findRedundantConnection(edges2);

  cout << "Redundant Connection in edges1: [" << result1[0] << ", " << result1[1] << "]" << endl;
  cout << "Redundant Connection in edges2: [" << result2[0] << ", " << result2[1] << "]" << endl;

  return 0;
}

/*
Time Complexity: O(E * α(N)), where E is the number of edges and α(N) is the inverse Ackermann function.
Space Complexity: O(N), where N is the number of nodes, used for storing parent and rank arrays.
*/
