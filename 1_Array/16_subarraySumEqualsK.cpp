#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int subarraySum(vector<int> &nums, int k)
  {
    int count = 0;                   // To store the count of subarrays whose sum equals k
    int sum = 0;                     // To keep track of the cumulative sum
    unordered_map<int, int> sumFreq; // To store the frequency of cumulative sums

    sumFreq[0] = 1; // Initialize with sum 0 frequency of 1

    // Traverse through the array
    for (int i = 0; i < nums.size(); i++)
    {
      sum += nums[i]; // Update cumulative sum

      // Check if there is a previous sum such that the current sum - previous sum equals k
      if (sumFreq.find(sum - k) != sumFreq.end())
      {
        count += sumFreq[sum - k]; // Increase count by the frequency of such sums
      }

      // Update the frequency of the current cumulative sum
      sumFreq[sum]++;
    }

    return count; // Return the total count of subarrays
  }
};

int main()
{
  Solution sol;

  // Example test cases
  vector<int> nums1 = {1, 1, 1};
  int k1 = 2;
  cout << "Number of subarrays with sum " << k1 << ": " << sol.subarraySum(nums1, k1) << endl;

  vector<int> nums2 = {1, 2, 3};
  int k2 = 3;
  cout << "Number of subarrays with sum " << k2 << ": " << sol.subarraySum(nums2, k2) << endl;

  return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(N)