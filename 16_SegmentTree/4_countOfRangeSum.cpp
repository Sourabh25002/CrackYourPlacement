#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countRangeSum(vector<int> &nums, int lower, int upper)
  {
    int n = nums.size();
    vector<long long> prefixSums(n + 1, 0);
    for (int i = 0; i < n; ++i)
    {
      prefixSums[i + 1] = prefixSums[i] + nums[i];
    }
    return countRangeSumHelper(prefixSums, 0, n, lower, upper);
  }

private:
  int countRangeSumHelper(vector<long long> &prefixSums, int start, int end, int lower, int upper)
  {
    if (start >= end - 1)
      return 0;
    int mid = start + (end - start) / 2;
    int count = countRangeSumHelper(prefixSums, start, mid, lower, upper) +
                countRangeSumHelper(prefixSums, mid, end, lower, upper);

    vector<long long> merged;
    int j = mid, k = mid;

    for (int i = start; i < mid; ++i)
    {
      while (j < end && prefixSums[j] - prefixSums[i] < lower)
        ++j;
      while (k < end && prefixSums[k] - prefixSums[i] <= upper)
        ++k;
      count += k - j;
      merged.push_back(prefixSums[i]);
    }
    for (int i = mid; i < end; ++i)
      merged.push_back(prefixSums[i]);
    sort(merged.begin(), merged.end());

    for (int i = start; i < end; ++i)
      prefixSums[start++] = merged[i - start];
    return count;
  }
};

int main()
{
  Solution sol;

  vector<int> nums1 = {-2, 5, -1};
  int lower1 = -2, upper1 = 2;
  cout << "Output for nums = [-2, 5, -1], lower = -2, upper = 2: "
       << sol.countRangeSum(nums1, lower1, upper1) << endl;

  vector<int> nums2 = {0};
  int lower2 = 0, upper2 = 0;
  cout << "Output for nums = [0], lower = 0, upper = 0: "
       << sol.countRangeSum(nums2, lower2, upper2) << endl;

  return 0;
}

/*
Time Complexity:
- O(n log n) for merge sort based approach.
Space Complexity:
- O(n) for storing prefix sums and merged vector.
*/
