#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
  {
    vector<vector<int>> graph(n);
    for (const auto &edge : edges)
    {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    vector<int> count(n, 1);  // Number of nodes in the subtree rooted at each node
    vector<int> result(n, 0); // Result array to store the sum of distances
    vector<bool> visited(n, false);

    // First DFS to calculate the count of nodes in each subtree and the initial distances
    function<void(int)> dfs1 = [&](int node)
    {
      visited[node] = true;
      for (int neighbor : graph[node])
      {
        if (!visited[neighbor])
        {
          dfs1(neighbor);
          count[node] += count[neighbor];
          result[node] += result[neighbor] + count[neighbor];
        }
      }
    };

    // Second DFS to adjust the result array based on the first node's result
    function<void(int)> dfs2 = [&](int node)
    {
      for (int neighbor : graph[node])
      {
        if (count[neighbor] < count[node])
        {
          result[neighbor] = result[node] - count[neighbor] + (n - count[neighbor]);
          dfs2(neighbor);
        }
      }
    };

    // Start DFS from node 0
    dfs1(0);
    fill(visited.begin(), visited.end(), false);
    dfs2(0);

    return result;
  }
};

int main()
{
  // Example usage:
  Solution sol;

  // Test Case 1
  int n1 = 6;
  vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}};
  vector<int> result1 = sol.sumOfDistancesInTree(n1, edges1);
  cout << "Output: ";
  for (int dist : result1)
    cout << dist << " ";
  cout << endl; // Output: [8, 12, 6, 10, 10, 10]

  // Test Case 2
  int n2 = 1;
  vector<vector<int>> edges2 = {};
  vector<int> result2 = sol.sumOfDistancesInTree(n2, edges2);
  cout << "Output: ";
  for (int dist : result2)
    cout << dist << " ";
  cout << endl; // Output: [0]

  // Test Case 3
  int n3 = 2;
  vector<vector<int>> edges3 = {{1, 0}};
  vector<int> result3 = sol.sumOfDistancesInTree(n3, edges3);
  cout << "Output: ";
  for (int dist : result3)
    cout << dist << " ";
  cout << endl; // Output: [1, 1]

  return 0;
}

/*
Time Complexity: O(N), where N is the number of nodes in the tree. Each node and edge is processed at most twice.
Space Complexity: O(N), for the graph representation, count, result, and visited arrays.
*/
