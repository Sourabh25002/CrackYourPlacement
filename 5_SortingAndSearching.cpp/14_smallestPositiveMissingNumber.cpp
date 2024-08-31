#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &arr)
{
  int n = arr.size();

  // Step 1: Remove elements that are not in the range [1, n]
  for (int i = 0; i < n; ++i)
  {
    while (arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i])
    {
      swap(arr[i], arr[arr[i] - 1]);
    }
  }

  // Step 2: Find the smallest missing positive number
  for (int i = 0; i < n; ++i)
  {
    if (arr[i] != i + 1)
    {
      return i + 1;
    }
  }

  // If all numbers from 1 to n are present, return n + 1
  return n + 1;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> arr1 = {1, 2, 3, 4, 5};
  cout << missingNumber(arr1) << endl; // Output: 6

  vector<int> arr2 = {0, -10, 1, 3, -20};
  cout << missingNumber(arr2) << endl; // Output: 2

  return 0;
}

/*
Time Complexity: O(N), as we are making a single pass through the array.
Space Complexity: O(1), as we are using in-place swaps and no extra space.
*/
