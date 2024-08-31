#include <bits/stdc++.h>
using namespace std;

// Function to calculate the cost of making all elements equal to 'target'
long long calculateCost(const vector<int> &arr, int target)
{
  long long cost = 0;
  for (int num : arr)
  {
    cost += abs(num - target);
  }
  return cost;
}

// Function to find the minimum cost to make all array elements equal
long long minCostToMakeEqual(const vector<int> &arr)
{
  int left = *min_element(arr.begin(), arr.end());
  int right = *max_element(arr.begin(), arr.end());

  while (right - left > 2)
  {
    int one_third = left + (right - left) / 3;
    int two_third = left + 2 * (right - left) / 3;

    long long cost1 = calculateCost(arr, one_third);
    long long cost2 = calculateCost(arr, two_third);

    if (cost1 < cost2)
    {
      right = two_third;
    }
    else
    {
      left = one_third;
    }
  }

  // Check the costs for the final range
  long long min_cost = LLONG_MAX;
  for (int i = left; i <= right; ++i)
  {
    min_cost = min(min_cost, calculateCost(arr, i));
  }

  return min_cost;
}

int main()
{
  vector<int> arr = {1, 100, 101}; // Example input
  cout << "Minimum cost to make all elements equal: " << minCostToMakeEqual(arr) << endl;

  arr = {4, 6}; // Another example input
  cout << "Minimum cost to make all elements equal: " << minCostToMakeEqual(arr) << endl;

  return 0;
}

/*
Time Complexity: O(n * log(range)), where n is the number of elements and range is the difference between the maximum and minimum values in the array.
Space Complexity: O(1), as we are using only a few additional variables.
*/
