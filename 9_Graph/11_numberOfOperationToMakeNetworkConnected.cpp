#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  class DisjointSet
  {
  public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
      rank.resize(n + 1, 0);
      parent.resize(n + 1);
      size.resize(n + 1);
      for (int i = 0; i <= n; i++)
      {
        parent[i] = i;
        size[i] = 1;
      }
    }

    int findUPar(int node)
    {
      if (node == parent[node])
        return node;
      return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
      int ulp_u = findUPar(u);
      int ulp_v = findUPar(v);
      if (ulp_u == ulp_v)
        return;
      if (rank[ulp_u] < rank[ulp_v])
      {
        parent[ulp_u] = ulp_v;
      }
      else if (rank[ulp_v] < rank[ulp_u])
      {
        parent[ulp_v] = ulp_u;
      }
      else
      {
        parent[ulp_v] = ulp_u;
        rank[ulp_u]++;
      }
    }

    void unionBySize(int u, int v)
    {
      int ulp_u = findUPar(u);
      int ulp_v = findUPar(v);
      if (ulp_u == ulp_v)
        return;
      if (size[ulp_u] < size[ulp_v])
      {
        parent[ulp_u] = ulp_v;
        size[ulp_v] += size[ulp_u];
      }
      else
      {
        parent[ulp_v] = ulp_u;
        size[ulp_u] += size[ulp_v];
      }
    }
  };

  int makeConnected(int n, vector<vector<int>> &connections)
  {
    if (connections.size() < n - 1)
      return -1; // Not enough cables to connect all nodes

    DisjointSet ds(n);
    for (auto &conn : connections)
    {
      ds.unionBySize(conn[0], conn[1]);
    }

    unordered_set<int> uniqueComponents;
    for (int i = 0; i < n; i++)
    {
      uniqueComponents.insert(ds.findUPar(i));
    }

    return uniqueComponents.size() - 1;
  }
};

int main()
{
  Solution sol;

  vector<vector<int>> connections1 = {{0, 1}, {0, 2}, {1, 2}};
  vector<vector<int>> connections2 = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};
  vector<vector<int>> connections3 = {{0, 1}, {0, 2}, {0, 3}, {1, 2}};

  cout << sol.makeConnected(4, connections1) << endl; // Output: 1
  cout << sol.makeConnected(6, connections2) << endl; // Output: 2
  cout << sol.makeConnected(6, connections3) << endl; // Output: -1

  return 0;
}

/*
Time Complexity: O(E * α(V)), where E is the number of connections and α is the inverse Ackermann function.
Space Complexity: O(V + E), for the Disjoint Set data structure.
*/
