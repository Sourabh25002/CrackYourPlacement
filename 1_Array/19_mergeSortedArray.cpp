#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
  {
    int i = m - 1;     // Pointer for the end of nums1's initialized part
    int j = n - 1;     // Pointer for the end of nums2
    int k = m + n - 1; // Pointer for the end of nums1's total length

    // Merge in reverse order
    while (j >= 0)
    {
      if (i >= 0 && nums1[i] > nums2[j])
      {
        nums1[k--] = nums1[i--];
      }
      else
      {
        nums1[k--] = nums2[j--];
      }
    }
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  vector<int> nums2 = {2, 5, 6};
  int m = 3, n = 3;
  sol.merge(nums1, m, nums2, n);
  cout << "Merged array 1: ";
  for (int num : nums1)
    cout << num << " ";
  cout << endl;

  // Example 2
  nums1 = {1};
  nums2 = {};
  m = 1, n = 0;
  sol.merge(nums1, m, nums2, n);
  cout << "Merged array 2: ";
  for (int num : nums1)
    cout << num << " ";
  cout << endl;

  // Example 3
  nums1 = {0};
  nums2 = {1};
  m = 0, n = 1;
  sol.merge(nums1, m, nums2, n);
  cout << "Merged array 3: ";
  for (int num : nums1)
    cout << num << " ";
  cout << endl;

  return 0;
}

// Time Complexity: O(m + n)
// Space Complexity: O(1)