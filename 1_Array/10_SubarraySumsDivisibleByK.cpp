#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int> &nums, int k)
{
  unordered_map<int, int> remainderCount;
  remainderCount[0] = 1; // Initialize with 0 remainder count
  int prefixSum = 0;
  int result = 0;

  for (int num : nums)
  {
    prefixSum += num;
    int remainder = (prefixSum % k + k) % k; // Handle negative remainders
    if (remainderCount.find(remainder) != remainderCount.end())
    {
      result += remainderCount[remainder];
    }
    remainderCount[remainder]++;
  }

  return result;
}

int main()
{
  vector<int> nums1 = {4, 5, 0, -2, -3, 1};
  int k1 = 5;
  cout << "Number of subarrays divisible by " << k1 << ": " << subarraysDivByK(nums1, k1) << endl;

  vector<int> nums2 = {5};
  int k2 = 9;
  cout << "Number of subarrays divisible by " << k2 << ": " << subarraysDivByK(nums2, k2) << endl;

  return 0;
}

// Time Complexity = O(N)
// Space Complexity = O(K)