#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> countSmaller(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> counts(n, 0);
    vector<pair<int, int>> numPairs(n);

    // Create pairs of (num, index)
    for (int i = 0; i < n; ++i)
    {
      numPairs[i] = {nums[i], i};
    }

    // Helper function to merge and count
    function<void(int, int, int)> mergeSort = [&](int left, int right, int idx)
    {
      if (left >= right)
        return;
      int mid = left + (right - left) / 2;
      mergeSort(left, mid, idx);
      mergeSort(mid + 1, right, idx);

      vector<pair<int, int>> temp(right - left + 1);
      int i = left, j = mid + 1, k = 0;

      while (i <= mid && j <= right)
      {
        if (numPairs[i].first <= numPairs[j].first)
        {
          counts[numPairs[i].second] += (j - mid - 1);
          temp[k++] = numPairs[i++];
        }
        else
        {
          temp[k++] = numPairs[j++];
        }
      }

      while (i <= mid)
      {
        counts[numPairs[i].second] += (j - mid - 1);
        temp[k++] = numPairs[i++];
      }

      while (j <= right)
      {
        temp[k++] = numPairs[j++];
      }

      for (int l = 0; l < temp.size(); ++l)
      {
        numPairs[left + l] = temp[l];
      }
    };

    mergeSort(0, n - 1, 0);
    return counts;
  }
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  Solution sol;

  vector<int> nums1 = {5, 2, 6, 1};
  vector<int> result1 = sol.countSmaller(nums1);
  for (int num : result1)
    cout << num << " ";
  cout << endl; // Output: 2 1 1 0

  vector<int> nums2 = {-1};
  vector<int> result2 = sol.countSmaller(nums2);
  for (int num : result2)
    cout << num << " ";
  cout << endl; // Output: 0

  vector<int> nums3 = {-1, -1};
  vector<int> result3 = sol.countSmaller(nums3);
  for (int num : result3)
    cout << num << " ";
  cout << endl; // Output: 0 0

  return 0;
}

/*
Time Complexity: O(n log n), due to merge sort.
Space Complexity: O(n), extra space for the temp array and counts vector.
*/
