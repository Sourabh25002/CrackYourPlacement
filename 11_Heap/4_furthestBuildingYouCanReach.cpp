#include <bits/stdc++.h>
using namespace std;

int furthestBuilding(vector<int> &heights, int bricks, int ladders)
{
  priority_queue<int, vector<int>, greater<int>> minHeap;
  int i = 0;

  for (i = 0; i < heights.size() - 1; i++)
  {
    int diff = heights[i + 1] - heights[i];

    if (diff > 0)
    {
      minHeap.push(diff); // Push the height difference into the min-heap
    }

    if (minHeap.size() > ladders)
    {
      // If there are more height differences than ladders, use bricks for the smallest difference
      bricks -= minHeap.top();
      minHeap.pop();
    }

    if (bricks < 0)
    {
      // If we run out of bricks, we cannot proceed further
      return i;
    }
  }

  return i; // Return the index of the furthest building we can reach
}

int main()
{
  vector<int> heights = {4, 2, 7, 6, 9, 14, 12};
  int bricks = 5;
  int ladders = 1;

  int result = furthestBuilding(heights, bricks, ladders);

  // Print the result
  cout << "The furthest building index you can reach is: " << result << endl;

  return 0;
}

// Time Complexity: O(N * log N)
// Space Complexity: O(N)