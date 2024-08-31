#include <bits/stdc++.h>
using namespace std;

// Function to find the cost of an optimal binary search tree
int optimalBST(vector<int> &keys, vector<int> &freq)
{
  int n = keys.size();

  // Table to store the cost of optimal binary search tree
  vector<vector<int>> cost(n, vector<int>(n, 0));

  // Table to store the sum of frequencies for subarrays
  vector<vector<int>> sumFreq(n, vector<int>(n, 0));

  // Initialize the sumFreq table
  for (int i = 0; i < n; ++i)
  {
    sumFreq[i][i] = freq[i];
    for (int j = i + 1; j < n; ++j)
    {
      sumFreq[i][j] = sumFreq[i][j - 1] + freq[j];
    }
  }

  // Fill the cost table
  for (int len = 1; len <= n; ++len)
  {
    for (int i = 0; i <= n - len; ++i)
    {
      int j = i + len - 1;
      if (len == 1)
      {
        cost[i][j] = freq[i];
      }
      else
      {
        cost[i][j] = INT_MAX;
        for (int r = i; r <= j; ++r)
        {
          int c = (r > i ? cost[i][r - 1] : 0) + (r < j ? cost[r + 1][j] : 0) + sumFreq[i][j];
          cost[i][j] = min(cost[i][j], c);
        }
      }
    }
  }

  return cost[0][n - 1];
}

int main()
{
  // Example 1
  vector<int> keys1 = {10, 12};
  vector<int> freq1 = {34, 50};
  cout << "Minimum cost for keys1: " << optimalBST(keys1, freq1) << endl; // Output: 118

  // Example 2
  vector<int> keys2 = {10, 12, 20};
  vector<int> freq2 = {34, 8, 50};
  cout << "Minimum cost for keys2: " << optimalBST(keys2, freq2) << endl; // Output: 142

  return 0;
}

/*
Time Complexity: O(n^3), where n is the number of keys
Space Complexity: O(n^2) for the cost and sumFreq tables
*/
