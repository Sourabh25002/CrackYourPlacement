#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string alienOrder(int n, int k, vector<string> &dict)
  {
    // Create a graph and indegree map
    vector<vector<int>> graph(k);
    vector<int> indegree(k, 0);

    // Build the graph
    for (int i = 0; i < n - 1; ++i)
    {
      string w1 = dict[i];
      string w2 = dict[i + 1];
      int len = min(w1.size(), w2.size());
      for (int j = 0; j < len; ++j)
      {
        if (w1[j] != w2[j])
        {
          int u = w1[j] - 'a';
          int v = w2[j] - 'a';
          if (find(graph[u].begin(), graph[u].end(), v) == graph[u].end())
          {
            graph[u].push_back(v);
            indegree[v]++;
          }
          break;
        }
      }
    }

    // Topological Sort using Kahn's Algorithm
    queue<int> q;
    string result;

    // Start with nodes having zero indegree
    for (int i = 0; i < k; ++i)
    {
      if (indegree[i] == 0)
      {
        q.push(i);
      }
    }

    while (!q.empty())
    {
      int node = q.front();
      q.pop();
      result += char(node + 'a');

      for (int neighbor : graph[node])
      {
        if (--indegree[neighbor] == 0)
        {
          q.push(neighbor);
        }
      }
    }

    // Check if we processed all nodes
    if (result.size() != k)
    {
      return "";
    }

    return result;
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<string> dict1 = {"baa", "abcd", "abca", "cab", "cad"};
  cout << (sol.alienOrder(5, 4, dict1) == "bdac" ? 1 : 0) << endl; // Output: 1 or 0 depending on the valid order

  // Example 2
  vector<string> dict2 = {"caa", "aaa", "aab"};
  cout << (sol.alienOrder(3, 3, dict2) == "cab" ? 1 : 0) << endl; // Output: 1 or 0 depending on the valid order

  return 0;
}

/*
Time Complexity: O(n * |s| + k), where n is the number of words, |s| is the length of words, and k is the number of distinct characters.
Space Complexity: O(k + n), for storing the graph, indegree, and result.
*/
