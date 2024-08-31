#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numPhoneNumbers(int n)
  {
    vector<vector<int>> dp(10, vector<int>(n + 1, 0));
    vector<vector<int>> moves = {
        {0, 8},                   // 0
        {1, 2, 4, 5},             // 1
        {2, 1, 3, 5, 8},          // 2
        {3, 2, 6, 5},             // 3
        {4, 1, 5, 7, 8},          // 4
        {5, 1, 2, 4, 6, 8, 9, 0}, // 5
        {6, 3, 5, 9},             // 6
        {7, 4, 8},                // 7
        {8, 0, 2, 4, 5, 7, 9},    // 8
        {9, 5, 6, 8}              // 9
    };

    // Initialize base case: length 1
    for (int i = 0; i < 10; ++i)
    {
      dp[i][1] = 1;
    }

    for (int length = 2; length <= n; ++length)
    {
      for (int digit = 0; digit < 10; ++digit)
      {
        for (int next : moves[digit])
        {
          dp[digit][length] += dp[next][length - 1];
        }
      }
    }

    int result = 0;
    for (int digit = 0; digit < 10; ++digit)
    {
      result += dp[digit][n];
    }

    return result;
  }
};

int main()
{
  Solution sol;

  int n1 = 1;
  cout << "Output for n = " << n1 << ": " << sol.numPhoneNumbers(n1) << endl; // Output: 10

  int n2 = 2;
  cout << "Output for n = " << n2 << ": " << sol.numPhoneNumbers(n2) << endl; // Output: 36

  return 0;
}

/*
Time Complexity: O(n * 10 * 10) ≈ O(n)
Space Complexity: O(10 * n) ≈ O(n)
*/
