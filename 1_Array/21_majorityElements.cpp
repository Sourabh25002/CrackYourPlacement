#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int majorityElement(vector<int> &nums)
  {
    int n = nums.size();
    int cnt = 0;
    int el;

    // Moore's Voting Algorithm
    for (int i = 0; i < n; i++)
    {
      if (cnt == 0)
      {
        el = nums[i];
        cnt++;
      }
      else if (nums[i] == el)
      {
        cnt++;
      }
      else
      {
        cnt--;
      }
    }

    return el;
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<int> nums1 = {3, 2, 3};
  cout << sol.majorityElement(nums1) << endl; // Output: 3

  // Example 2
  vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
  cout << sol.majorityElement(nums2) << endl; // Output: 2

  return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)