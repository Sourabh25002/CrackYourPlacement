#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Function to check if it's safe to color vertex u with color c
  bool isSafe(int u, vector<vector<int>> &graph, vector<int> &color, int c)
  {
    for (int v : graph[u])
    {
      if (color[v] == c)
      {
        return false;
      }
    }
    return true;
  }

  // Recursive function to solve the graph coloring problem
  bool graphColoringUtil(vector<vector<int>> &graph, vector<int> &color, int m, int v)
  {
    int V = graph.size();
    if (v == V)
    {
      return true;
    }

    for (int c = 1; c <= m; c++)
    {
      if (isSafe(v, graph, color, c))
      {
        color[v] = c;
        if (graphColoringUtil(graph, color, m, v + 1))
        {
          return true;
        }
        color[v] = 0; // Backtrack
      }
    }
    return false;
  }

  // Function to solve the graph coloring problem
  bool graphColoring(vector<vector<int>> &graph, int m)
  {
    int V = graph.size();
    vector<int> color(V, 0); // Initialize color array

    return graphColoringUtil(graph, color, m, 0);
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<vector<int>> graph1 = {
      {1, 2, 3},
      {0, 2},
      {0, 1, 3},
      {0, 2}};
  int m1 = 3;

  // Example 2
  vector<vector<int>> graph2 = {
      {1, 2},
      {0, 2},
      {0, 1}};
  int m2 = 2;

  bool result1 = sol.graphColoring(graph1, m1);
  bool result2 = sol.graphColoring(graph2, m2);

  cout << "Graph 1 can be colored with " << m1 << " colors: " << (result1 ? "Yes" : "No") << endl;
  cout << "Graph 2 can be colored with " << m2 << " colors: " << (result2 ? "Yes" : "No") << endl;

  return 0;
}

/*
Time Complexity: O(m^V * V^2), where V is the number of vertices and m is the number of colors.
Space Complexity: O(V), for the color array and recursive stack.
*/
