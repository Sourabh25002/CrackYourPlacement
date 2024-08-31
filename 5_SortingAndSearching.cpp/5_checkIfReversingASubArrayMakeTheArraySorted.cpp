#include <bits/stdc++.h>
using namespace std;

bool canBeSortedByReversingSubarray(vector<int> &arr)
{
  vector<int> sortedArr = arr;
  sort(sortedArr.begin(), sortedArr.end());

  // Find the first and last index where the original array and sorted array differ
  int start = 0, end = arr.size() - 1;

  while (start < arr.size() && arr[start] == sortedArr[start])
  {
    ++start;
  }

  if (start == arr.size())
  {
    return true; // The array is already sorted
  }

  while (end >= 0 && arr[end] == sortedArr[end])
  {
    --end;
  }

  // Check if reversing the subarray from start to end sorts the array
  reverse(arr.begin() + start, arr.begin() + end + 1);

  return arr == sortedArr;
}

int main()
{
  vector<int> arr1 = {1, 2, 5, 4, 3};
  cout << (canBeSortedByReversingSubarray(arr1) ? "Yes" : "No") << endl; // Output: Yes

  vector<int> arr2 = {1, 2, 4, 5, 3};
  cout << (canBeSortedByReversingSubarray(arr2) ? "Yes" : "No") << endl; // Output: No

  return 0;
}

/*
Time Complexity: O(n * log(n)), due to sorting and checking.
Space Complexity: O(n), due to the space required for sorting the array.
*/
