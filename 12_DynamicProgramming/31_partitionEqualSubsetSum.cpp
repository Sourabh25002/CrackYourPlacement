#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int equalPartition(int N, int arr[])
  {
    int sum = accumulate(arr, arr + N, 0);

    // If the total sum is odd, it's not possible to partition the array into two equal subsets
    if (sum % 2 != 0)
      return 0;

    int target = sum / 2;
    vector<vector<bool>> dp(N + 1, vector<bool>(target + 1, false));

    // Initialize dp array
    for (int i = 0; i <= N; ++i)
      dp[i][0] = true;

    for (int i = 1; i <= N; ++i)
    {
      for (int j = 1; j <= target; ++j)
      {
        if (arr[i - 1] <= j)
        {
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
        }
        else
        {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }

    return dp[N][target] ? 1 : 0;
  }
};

int main()
{
  Solution sol;

  int arr1[] = {1, 5, 11, 5};
  int N1 = sizeof(arr1) / sizeof(arr1[0]);
  cout << "Example 1 Output: " << (sol.equalPartition(N1, arr1) == 1 ? "YES" : "NO") << endl; // Output: YES

  int arr2[] = {1, 3, 5};
  int N2 = sizeof(arr2) / sizeof(arr2[0]);
  cout << "Example 2 Output: " << (sol.equalPartition(N2, arr2) == 1 ? "YES" : "NO") << endl; // Output: NO

  return 0;
}

/*
Time Complexity: O(N * sum), where N is the number of elements and sum is the target sum.
Space Complexity: O(N * sum), due to the DP table used to store subproblem results.
*/
