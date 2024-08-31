#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int sumSubarrayMins(vector<int> &arr)
  {
    const int MOD = 1e9 + 7;
    int n = arr.size();

    // Arrays to store previous less element and next less element indexes
    vector<int> prevLess(n, -1), nextLess(n, n);
    stack<int> s;

    // Calculate previous less element for each element in the array
    for (int i = 0; i < n; ++i)
    {
      while (!s.empty() && arr[s.top()] >= arr[i])
      {
        s.pop();
      }
      if (!s.empty())
      {
        prevLess[i] = s.top();
      }
      s.push(i);
    }

    // Clear the stack to reuse it for the next less elements
    while (!s.empty())
      s.pop();

    // Calculate next less element for each element in the array
    for (int i = n - 1; i >= 0; --i)
    {
      while (!s.empty() && arr[s.top()] > arr[i])
      {
        s.pop();
      }
      if (!s.empty())
      {
        nextLess[i] = s.top();
      }
      s.push(i);
    }

    long long result = 0;

    // Calculate the sum of the minimums of all subarrays
    for (int i = 0; i < n; ++i)
    {
      long long leftCount = i - prevLess[i];
      long long rightCount = nextLess[i] - i;
      result = (result + arr[i] * leftCount * rightCount) % MOD;
    }

    return result;
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<int> arr1 = {3, 1, 2, 4};
  cout << "Example 1 Output: " << sol.sumSubarrayMins(arr1) << endl;

  // Example 2
  vector<int> arr2 = {11, 81, 94, 43, 3};
  cout << "Example 2 Output: " << sol.sumSubarrayMins(arr2) << endl;

  return 0;
}

/*
Time Complexity: O(n) where n is the length of the array. The solution iterates through the array multiple times, but each iteration is linear.

Space Complexity: O(n) due to the use of stacks and auxiliary arrays for storing previous and next less element indexes.
*/
