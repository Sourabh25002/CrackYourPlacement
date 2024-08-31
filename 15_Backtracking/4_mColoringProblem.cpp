#include <bits/stdc++.h>
using namespace std;

// Function to check if it's possible to color the graph using M colors
bool isSafe(vector<vector<int>> &graph, vector<int> &color, int node, int c, int N)
{
  for (int i = 0; i < N; ++i)
  {
    if (graph[node][i] && color[i] == c)
    {
      return false;
    }
  }
  return true;
}

bool graphColoringUtil(vector<vector<int>> &graph, vector<int> &color, int node, int M, int N)
{
  if (node == N)
  {
    return true;
  }

  for (int c = 1; c <= M; ++c)
  {
    if (isSafe(graph, color, node, c, N))
    {
      color[node] = c;
      if (graphColoringUtil(graph, color, node + 1, M, N))
      {
        return true;
      }
      color[node] = 0; // Backtrack
    }
  }

  return false;
}

int graphColoring(vector<vector<int>> &graph, int M, int N)
{
  vector<int> color(N, 0);
  return graphColoringUtil(graph, color, 0, M, N) ? 1 : 0;
}

int main()
{
  int N, M, E;
  cin >> N >> M >> E;

  vector<vector<int>> graph(N, vector<int>(N, 0));
  for (int i = 0; i < E; ++i)
  {
    int u, v;
    cin >> u >> v;
    graph[u][v] = 1;
    graph[v][u] = 1; // Because the graph is undirected
  }

  cout << graphColoring(graph, M, N) << endl;

  return 0;
}

/*
Time Complexity: O(M^N) in the worst case, as we try every color for every vertex.
Space Complexity: O(N) for the recursion stack and color array.
*/
