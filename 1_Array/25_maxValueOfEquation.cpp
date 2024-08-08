#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findMaxValueOfEquation(vector<vector<int>> &points, int k)
  {
    // Priority queue to store pairs of (yi - xi, xi) with max-heap
    priority_queue<pair<int, int>> pq;
    // Initialize the priority queue with the first point
    pq.push({points[0][1] - points[0][0], points[0][0]});
    int ans = INT_MIN;

    for (int i = 1; i < points.size(); i++)
    {
      int xi = points[i][0];
      int yi = points[i][1];

      // Remove points from the queue where |xi - xj| > k
      while (!pq.empty() && xi - pq.top().second > k)
      {
        pq.pop();
      }

      // If the queue is not empty, calculate the current max value
      if (!pq.empty())
      {
        ans = max(ans, yi + xi + pq.top().first);
      }

      // Push the current (yi - xi, xi) into the priority queue
      pq.push({yi - xi, xi});
    }

    return ans;
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<vector<int>> points1 = {{1, 3}, {2, 0}, {5, 10}, {6, -10}};
  int k1 = 1;
  cout << "Max Value of Equation: " << sol.findMaxValueOfEquation(points1, k1) << endl; // Output: 4

  // Example 2
  vector<vector<int>> points2 = {{0, 0}, {3, 0}, {9, 2}};
  int k2 = 3;
  cout << "Max Value of Equation: " << sol.findMaxValueOfEquation(points2, k2) << endl; // Output: 3

  return 0;
}

// Time Complexity: O(n log n)
// Space Complexity: O(n)