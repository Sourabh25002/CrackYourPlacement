#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Helper function to perform DFS
  double dfs(const string &start, const string &end, unordered_map<string, unordered_map<string, double>> &graph, unordered_set<string> &visited)
  {
    if (graph.find(start) == graph.end() || graph.find(end) == graph.end())
      return -1.0;
    if (start == end)
      return 1.0;

    visited.insert(start);
    for (const auto &[neighbor, weight] : graph[start])
    {
      if (visited.find(neighbor) != visited.end())
        continue;
      double result = dfs(neighbor, end, graph, visited);
      if (result != -1.0)
        return result * weight;
    }

    return -1.0;
  }

  vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
  {
    // Create an adjacency list for the graph
    unordered_map<string, unordered_map<string, double>> graph;

    // Build the graph
    for (int i = 0; i < equations.size(); ++i)
    {
      const string &src = equations[i][0];
      const string &dst = equations[i][1];
      double value = values[i];

      graph[src][dst] = value;
      graph[dst][src] = 1.0 / value;
    }

    vector<double> results;
    for (const auto &query : queries)
    {
      const string &start = query[0];
      const string &end = query[1];
      unordered_set<string> visited;
      results.push_back(dfs(start, end, graph, visited));
    }

    return results;
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<vector<string>> equations1 = {{"a", "b"}, {"b", "c"}};
  vector<double> values1 = {2.0, 3.0};
  vector<vector<string>> queries1 = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
  vector<double> result1 = sol.calcEquation(equations1, values1, queries1);
  for (double val : result1)
  {
    cout << fixed << setprecision(5) << val << " ";
  }
  cout << endl;

  // Example 2
  vector<vector<string>> equations2 = {{"a", "b"}, {"b", "c"}, {"bc", "cd"}};
  vector<double> values2 = {1.5, 2.5, 5.0};
  vector<vector<string>> queries2 = {{"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"}};
  vector<double> result2 = sol.calcEquation(equations2, values2, queries2);
  for (double val : result2)
  {
    cout << fixed << setprecision(5) << val << " ";
  }
  cout << endl;

  // Example 3
  vector<vector<string>> equations3 = {{"a", "b"}};
  vector<double> values3 = {0.5};
  vector<vector<string>> queries3 = {{"a", "b"}, {"b", "a"}, {"a", "c"}, {"x", "y"}};
  vector<double> result3 = sol.calcEquation(equations3, values3, queries3);
  for (double val : result3)
  {
    cout << fixed << setprecision(5) << val << " ";
  }
  cout << endl;

  return 0;
}

/*
Time Complexity: O(E + Q * (V + E)) where E is the number of edges, Q is the number of queries, and V is the number of vertices.
Space Complexity: O(E + V^2) due to storing the graph and visited states.
*/
