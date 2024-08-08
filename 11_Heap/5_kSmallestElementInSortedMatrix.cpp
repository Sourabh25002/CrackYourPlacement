#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int kthSmallest(vector<vector<int>> &matrix, int k)
  {
    int n = matrix.size();
    // Min-heap to store elements along with their positions (value, (row, col))
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;

    // Initialize the min-heap with the first element of each row
    for (int i = 0; i < n; ++i)
    {
      minHeap.push({matrix[i][0], {i, 0}});
    }

    int count = 0;
    while (count < k)
    {
      auto [val, pos] = minHeap.top();
      minHeap.pop();
      auto [row, col] = pos;

      count++;
      if (count == k)
        return val; // Return the k-th smallest element

      // Push the next element from the same row into the heap
      if (col + 1 < n)
      {
        minHeap.push({matrix[row][col + 1], {row, col + 1}});
      }
    }

    return -1; // This line should never be reached
  }
};

int main()
{
  // Example test case
  Solution sol;
  vector<vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
  int k = 8;
  int result = sol.kthSmallest(matrix, k);

  // Print the result
  cout << "The " << k << "th smallest element is: " << result << endl;

  return 0;
}

// Time Complexity: O(k * log n)
// Space Complexity: O(n)