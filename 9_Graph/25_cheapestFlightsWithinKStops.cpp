#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
  {
    // Initialize distance vector with a large value
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // Relax edges up to k+1 times
    for (int i = 0; i <= k; ++i)
    {
      vector<int> temp = dist;
      for (const auto &flight : flights)
      {
        int u = flight[0], v = flight[1], price = flight[2];
        if (dist[u] != INT_MAX && dist[u] + price < temp[v])
        {
          temp[v] = dist[u] + price;
        }
      }
      dist = temp;
    }

    return dist[dst] == INT_MAX ? -1 : dist[dst];
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<vector<int>> flights1 = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
  cout << sol.findCheapestPrice(4, flights1, 0, 3, 1) << endl; // Output: 700

  // Example 2
  vector<vector<int>> flights2 = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
  cout << sol.findCheapestPrice(3, flights2, 0, 2, 1) << endl; // Output: 200

  // Example 3
  vector<vector<int>> flights3 = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
  cout << sol.findCheapestPrice(3, flights3, 0, 2, 0) << endl; // Output: 500

  return 0;
}

/*
Time Complexity: O(k * E), where k is the maximum number of stops and E is the number of edges.
Space Complexity: O(n), where n is the number of cities.
*/
