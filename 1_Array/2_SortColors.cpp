#include <bits/stdc++.h>
using namespace std;

void sortArray(vector<int> &arr, int n)
{
  int low = 0, mid = 0, high = n - 1;
  while (mid <= high)
  {
    if (arr[mid] == 0)
    {
      swap(arr[low], arr[mid]);
      low++;
      mid++;
    }
    else if (arr[mid] == 1)
    {
      mid++;
    }
    else
    {
      swap(arr[mid], arr[high]);
      high--;
    }
  }
}

void sortColors(vector<int> &nums)
{
  sortArray(nums, nums.size());
}

int main()
{
  vector<int> nums = {2, 0, 2, 1, 1, 0};
  sortColors(nums);
  cout << "Sorted array: ";
  for (int num : nums)
  {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}

// Time Complexity = O(N)
// Space Complexity = O(1)