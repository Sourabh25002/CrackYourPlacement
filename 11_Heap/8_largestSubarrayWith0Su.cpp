#include <bits/stdc++.h>
using namespace std;

int maxLen(vector<int> &arr, int n)
{
  unordered_map<int, int> sumMap; // Map to store the first occurrence of each cumulative sum
  int max_len = 0;
  int sum = 0;

  for (int i = 0; i < n; ++i)
  {
    sum += arr[i]; // Add the current element to the cumulative sum

    if (sum == 0)
    {
      max_len = i + 1; // If the cumulative sum is 0, the subarray from the start to the current index has a sum of 0
    }
    else
    {
      if (sumMap.find(sum) != sumMap.end())
      {
        // If the sum is already seen, calculate the subarray length
        max_len = max(max_len, i - sumMap[sum]);
      }
      else
      {
        // Otherwise, store the index of this sum's first occurrence
        sumMap[sum] = i;
      }
    }
  }

  return max_len;
}

int main()
{
  vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
  int n = arr.size();
  cout << "Length of the largest subarray with sum 0: " << maxLen(arr, n) << endl;
  return 0;
}

/*
Time Complexity:
- The algorithm iterates through the array once (O(n)).
- Each operation with the unordered_map (insertion and lookup) is O(1) on average.
- Therefore, the overall time complexity is O(n).

Space Complexity:
- The space used is primarily for the unordered_map, which stores at most n entries (one for each element in the array).
- Hence, the space complexity is O(n).
*/
