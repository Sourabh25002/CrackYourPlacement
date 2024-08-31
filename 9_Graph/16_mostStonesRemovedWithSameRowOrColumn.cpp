#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  static int findParent(vector<int> &parent, int node)
  {
    if (node == parent[node])
    {
      return node;
    }
    return parent[node] = findParent(parent, parent[node]);
  }

  static bool unionn(vector<int> &parent, vector<int> &rank, int u, int v)
  {
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (u == v)
    {
      return false;
    }

    if (rank[u] < rank[v])
    {
      parent[u] = v;
    }
    else if (rank[u] > rank[v])
    {
      parent[v] = u;
    }
    else
    {
      parent[v] = u;
      rank[u]++;
    }
    return true;
  }

  int removeStones(vector<vector<int>> &stones)
  {
    int N = stones.size();

    // Initialize parent and rank vectors
    vector<int> parent(N);
    vector<int> rank(N, 0);
    iota(parent.begin(), parent.end(), 0); // parent[i] = i

    // Map to track rows and columns
    unordered_map<int, int> rowMap;
    unordered_map<int, int> colMap;

    // Union-find based approach
    for (int i = 0; i < N; i++)
    {
      int row = stones[i][0];
      int col = stones[i][1];

      if (rowMap.find(row) != rowMap.end())
      {
        unionn(parent, rank, i, rowMap[row]);
      }
      if (colMap.find(col) != colMap.end())
      {
        unionn(parent, rank, i, colMap[col]);
      }

      rowMap[row] = i;
      colMap[col] = i;
    }

    // Count the number of unique components
    unordered_set<int> uniqueParents;
    for (int i = 0; i < N; i++)
    {
      uniqueParents.insert(findParent(parent, i));
    }

    // Number of stones that can be removed
    return N - uniqueParents.size();
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<vector<int>> stones1 = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
  // Example 2
  vector<vector<int>> stones2 = {{0, 0}, {0, 2}, {1, 1}, {2, 0}, {2, 2}};
  // Example 3
  vector<vector<int>> stones3 = {{0, 0}};

  int result1 = sol.removeStones(stones1);
  int result2 = sol.removeStones(stones2);
  int result3 = sol.removeStones(stones3);

  cout << "Example 1: " << result1 << endl; // Output: 5
  cout << "Example 2: " << result2 << endl; // Output: 3
  cout << "Example 3: " << result3 << endl; // Output: 0

  return 0;
}

/*
Time Complexity: O(N^2) in the worst case, where N is the number of stones.
Space Complexity: O(N) for the parent, rank, and mapping storage.
*/
