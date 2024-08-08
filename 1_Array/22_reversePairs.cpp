#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  void merge(vector<int> &nums, int low, int mid, int high, int &reversePairsCount)
  {
    int j = mid + 1;

    // Count reverse pairs
    for (int i = low; i <= mid; i++)
    {
      while (j <= high && nums[i] > 2 * (long long)nums[j])
      {
        j++;
      }
      reversePairsCount += (j - (mid + 1));
    }

    // Merge the two sorted halves
    int size = high - low + 1;
    vector<int> temp(size, 0);
    int left = low, right = mid + 1, k = 0;

    while (left <= mid && right <= high)
    {
      if (nums[left] <= nums[right])
      {
        temp[k++] = nums[left++];
      }
      else
      {
        temp[k++] = nums[right++];
      }
    }

    while (left <= mid)
    {
      temp[k++] = nums[left++];
    }

    while (right <= high)
    {
      temp[k++] = nums[right++];
    }

    // Copy the merged array back to nums
    for (int i = 0; i < size; i++)
    {
      nums[low + i] = temp[i];
    }
  }

  void mergeSort(vector<int> &nums, int low, int high, int &reversePairsCount)
  {
    if (low >= high)
    {
      return;
    }

    int mid = low + (high - low) / 2;
    mergeSort(nums, low, mid, reversePairsCount);
    mergeSort(nums, mid + 1, high, reversePairsCount);
    merge(nums, low, mid, high, reversePairsCount);
  }

public:
  int reversePairs(vector<int> &nums)
  {
    int reversePairsCount = 0;
    mergeSort(nums, 0, nums.size() - 1, reversePairsCount);
    return reversePairsCount;
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<int> nums1 = {1, 3, 2, 3, 1};
  cout << sol.reversePairs(nums1) << endl; // Output: 2

  // Example 2
  vector<int> nums2 = {2, 4, 3, 5, 1};
  cout << sol.reversePairs(nums2) << endl; // Output: 3

  return 0;
}

// Time Complexity: O(n log n)
// Space Complexity: O(n)