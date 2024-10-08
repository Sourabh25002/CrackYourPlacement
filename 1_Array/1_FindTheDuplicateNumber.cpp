#include <bits/stdc++.h>
using namespace std;

int duplicateNumber(vector<int> nums)
{
  int slow = nums[0];
  int fast = nums[0];

  do
  {
    slow = nums[slow];
    fast = nums[nums[fast]];
  } while (slow != fast);

  fast = nums[0];
  while (slow != fast)
  {
    slow = nums[slow];
    fast = nums[fast];
  }

  return slow;
}

int main()
{

  vector<int> nums = {1, 3, 4, 2, 2};
  cout << "The Duplicate number is: " << duplicateNumber(nums) << endl;

  return 0;
}

// Time Complexity = O(N)
// Space Complexity = O(1)