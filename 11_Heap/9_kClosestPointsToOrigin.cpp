#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Comparator for the max-heap
  struct Compare
  {
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
      return a.first < b.first; // Max-heap based on distance
    }
  };

  vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
  {
    // Max-heap to store the k closest points with the largest distances at the top
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> maxHeap;

    // Calculate squared distance and maintain only k smallest distances in the heap
    for (int i = 0; i < points.size(); i++)
    {
      int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
      if (maxHeap.size() < k)
      {
        maxHeap.push({dist, i});
      }
      else if (dist < maxHeap.top().first)
      {
        maxHeap.pop();
        maxHeap.push({dist, i});
      }
    }

    // Collect the k closest points
    vector<vector<int>> result;
    while (!maxHeap.empty())
    {
      result.push_back(points[maxHeap.top().second]);
      maxHeap.pop();
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
  int k = 2;
  vector<vector<int>> result = sol.kClosest(points, k);

  cout << "The " << k << " closest points to the origin are:" << endl;
  for (auto &point : result)
  {
    cout << "[" << point[0] << ", " << point[1] << "]" << endl;
  }

  return 0;
}

/*
Time Complexity:
- The time complexity of the solution is O(n log k), where n is the number of points.
- Inserting an element into the heap and extracting the maximum element both take O(log k) time, and we do this n times.

Space Complexity:
- The space complexity is O(k), which is the space required to store the k closest points in the heap.
*/
