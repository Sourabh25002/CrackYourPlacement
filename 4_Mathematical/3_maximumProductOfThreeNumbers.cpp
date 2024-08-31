#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maximumProduct(vector<int> &nums)
  {
    // Sort the array
    sort(nums.begin(), nums.end());

    // The maximum product can be obtained by either:
    // 1. The product of the three largest numbers (last three in the sorted array)
    // 2. The product of the two smallest numbers (negative) and the largest number
    int n = nums.size();
    return max(nums[n - 1] * nums[n - 2] * nums[n - 3],
               nums[0] * nums[1] * nums[n - 1]);
  }
};

int main()
{
  Solution sol;

  int n;
  cout << "Input the number of elements in the array: ";
  cin >> n;

  vector<int> nums(n);
  cout << "Input the elements of the array: ";
  for (int i = 0; i < n; ++i)
  {
    cin >> nums[i];
  }

  cout << "Maximum product of three numbers: " << sol.maximumProduct(nums) << endl;

  return 0;
}

/*
Time Complexity: O(n log n), where n is the number of elements in the input array due to sorting.
Space Complexity: O(1), as no additional space is used apart from a few variables.
*/
