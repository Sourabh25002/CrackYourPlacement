#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void sortColors(vector<int> &nums)
  {
    int low = 0, mid = 0, high = nums.size() - 1;

    while (mid <= high)
    {
      if (nums[mid] == 0)
      {
        swap(nums[low++], nums[mid++]);
      }
      else if (nums[mid] == 1)
      {
        mid++;
      }
      else
      {
        swap(nums[mid], nums[high--]);
      }
    }
  }
};

int main()
{
  Solution sol;

  vector<int> nums1 = {2, 0, 2, 1, 1, 0};
  sol.sortColors(nums1);
  cout << "Example 1 Output: ";
  for (int num : nums1)
  {
    cout << num << " ";
  }
  cout << endl; // Output: 0 0 1 1 2 2

  vector<int> nums2 = {2, 0, 1};
  sol.sortColors(nums2);
  cout << "Example 2 Output: ";
  for (int num : nums2)
  {
    cout << num << " ";
  }
  cout << endl; // Output: 0 1 2

  return 0;
}

/*
Time Complexity: O(n), where n is the length of the array.
Space Complexity: O(1), as no extra space is used.
*/
