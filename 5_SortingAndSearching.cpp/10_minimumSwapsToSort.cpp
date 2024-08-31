#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum number of swaps required to sort the array
int minSwaps(vector<int> &nums)
{
  int n = nums.size();
  vector<pair<int, int>> arr(n);

  // Create a pair of element and its index
  for (int i = 0; i < n; ++i)
  {
    arr[i] = {nums[i], i};
  }

  // Sort the array based on the element values
  sort(arr.begin(), arr.end());

  // Array to keep track of visited elements
  vector<bool> visited(n, false);

  int swaps = 0;

  for (int i = 0; i < n; ++i)
  {
    // If already visited or already in the correct place, skip
    if (visited[i] || arr[i].second == i)
    {
      continue;
    }

    // Calculate the size of the cycle
    int cycle_size = 0;
    int j = i;

    while (!visited[j])
    {
      visited[j] = true;
      j = arr[j].second; // Move to the next index in the cycle
      ++cycle_size;
    }

    // If there is a cycle of size 'cycle_size', it takes (cycle_size - 1) swaps to sort it
    if (cycle_size > 1)
    {
      swaps += (cycle_size - 1);
    }
  }

  return swaps;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> nums1 = {2, 8, 5, 4};
  vector<int> nums2 = {10, 19, 6, 3, 5};

  cout << minSwaps(nums1) << endl; // Output: 1
  cout << minSwaps(nums2) << endl; // Output: 2

  return 0;
}

/*
Time Complexity: O(n log n), due to sorting.
Space Complexity: O(n), for storing the array of pairs and visited vector.
*/
