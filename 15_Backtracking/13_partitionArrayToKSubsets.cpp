#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isKPartitionPossible(vector<int> &a, int N, int K)
  {
    int sum = accumulate(a.begin(), a.end(), 0);
    if (sum % K != 0)
      return false;
    int subsetSum = sum / K;

    vector<bool> visited(N, false);
    function<bool(int, int, int, int)> canPartition = [&](int start, int currentSum, int count, int k)
    {
      if (k == 1)
        return true; // If one subset is left, the remaining elements must form a valid subset
      if (currentSum == subsetSum)
        return canPartition(0, 0, 0, k - 1);
      for (int i = start; i < N; ++i)
      {
        if (!visited[i] && currentSum + a[i] <= subsetSum)
        {
          visited[i] = true;
          if (canPartition(i + 1, currentSum + a[i], count + 1, k))
            return true;
          visited[i] = false;
        }
      }
      return false;
    };

    return canPartition(0, 0, 0, K);
  }
};

int main()
{
  Solution sol;

  vector<int> a1 = {2, 1, 4, 5, 6};
  int N1 = 5, K1 = 3;
  cout << sol.isKPartitionPossible(a1, N1, K1) << endl; // Output: 1

  vector<int> a2 = {2, 1, 5, 5, 6};
  int N2 = 5, K2 = 3;
  cout << sol.isKPartitionPossible(a2, N2, K2) << endl; // Output: 0

  return 0;
}

/*
Time Complexity: O(N * 2^N), where N is the size of the array. This is due to the exploration of subsets.
Space Complexity: O(2^N), due to the recursion stack and the usage of the visited array.
*/
