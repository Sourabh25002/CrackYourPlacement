#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int> &nums)
{
  vector<int> result;
  for (int num : nums)
  {
    int index = abs(num) - 1;
    if (nums[index] < 0)
    {
      result.push_back(abs(num));
    }
    else
    {
      nums[index] = -nums[index];
    }
  }
  return result;
}

int main()
{
  vector<int> nums1 = {4, 3, 2, 7, 8, 2, 3, 1};
  vector<int> nums2 = {1, 1, 2};
  vector<int> nums3 = {1};

  vector<int> result1 = findDuplicates(nums1);
  vector<int> result2 = findDuplicates(nums2);
  vector<int> result3 = findDuplicates(nums3);

  cout << "Duplicates in nums1: ";
  for (int num : result1)
    cout << num << " ";
  cout << endl;

  cout << "Duplicates in nums2: ";
  for (int num : result2)
    cout << num << " ";
  cout << endl;

  cout << "Duplicates in nums3: ";
  for (int num : result3)
    cout << num << " ";
  cout << endl;

  return 0;
}

// Time Complexity = O(N)
// Space Complexity = O(1)