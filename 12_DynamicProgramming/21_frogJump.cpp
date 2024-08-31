#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool canCross(vector<int> &stones)
  {
    int n = stones.size();
    unordered_map<int, unordered_set<int>> dp;
    dp[0].insert(0); // Starting position with a jump of 0

    for (int i = 0; i < n; ++i)
    {
      int stone = stones[i];
      for (int jump : dp[stone])
      {
        for (int k = jump - 1; k <= jump + 1; ++k)
        {
          if (k > 0 && dp.count(stone + k))
          {
            dp[stone + k].insert(k);
          }
        }
      }
    }

    return !dp[stones.back()].empty();
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<int> stones1 = {0, 1, 3, 5, 6, 8, 12, 17};
  cout << "Output for stones1: " << (sol.canCross(stones1) ? "true" : "false") << endl; // Output: true

  // Example 2
  vector<int> stones2 = {0, 1, 2, 3, 4, 8, 9, 11};
  cout << "Output for stones2: " << (sol.canCross(stones2) ? "true" : "false") << endl; // Output: false

  return 0;
}

/*
Time Complexity: O(n^2), where n is the number of stones. Each stone could potentially involve checking up to n jumps.
Space Complexity: O(n^2), due to the storage of jump possibilities in the unordered_map.
*/
