#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
  {
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    // Initialize distances based on edges
    for (auto &edge : edges)
    {
      int u = edge[0], v = edge[1], weight = edge[2];
      dist[u][v] = weight;
      dist[v][u] = weight;
    }

    // Distance from a node to itself is 0
    for (int i = 0; i < n; i++)
    {
      dist[i][i] = 0;
    }

    // Floyd-Warshall algorithm to find shortest paths
    for (int k = 0; k < n; k++)
    {
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < n; j++)
        {
          if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX)
          {
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
          }
        }
      }
    }

    int minCount = n;
    int cityNo = -1;

    // Find the city with the smallest number of neighbors within distanceThreshold
    for (int city = 0; city < n; city++)
    {
      int count = 0;
      for (int adjCity = 0; adjCity < n; adjCity++)
      {
        if (dist[city][adjCity] <= distanceThreshold)
        {
          count++;
        }
      }
      if (count <= minCount)
      {
        minCount = count;
        cityNo = city;
      }
    }

    return cityNo;
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<vector<int>> edges1 = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
  int distanceThreshold1 = 4;
  // Example 2
  vector<vector<int>> edges2 = {{0, 1, 2}, {0, 4, 8}, {1, 2, 3}, {1, 4, 2}, {2, 3, 1}, {3, 4, 1}};
  int distanceThreshold2 = 2;

  int result1 = sol.findTheCity(4, edges1, distanceThreshold1);
  int result2 = sol.findTheCity(5, edges2, distanceThreshold2);

  cout << "Example 1: " << result1 << endl; // Output: 3
  cout << "Example 2: " << result2 << endl; // Output: 0

  return 0;
}

/*
Time Complexity: O(n^3), where n is the number of cities. This is due to the Floyd-Warshall algorithm which has cubic complexity.
Space Complexity: O(n^2), for storing the distance matrix.
*/
