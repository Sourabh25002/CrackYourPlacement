#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
  // Min-heap to store the k largest elements
  priority_queue<int, vector<int>, greater<int>> minHeap;

  // Iterate through each element in the array
  for (int num : nums)
  {
    minHeap.push(num); // Push the current number into the heap

    // If the size of the heap exceeds k, pop the smallest element
    if (minHeap.size() > k)
    {
      minHeap.pop(); // Remove the smallest element
    }
  }

  // The root of the heap is the k-th largest element
  return minHeap.top();
}

int main()
{
  vector<int> nums = {3, 2, 1, 5, 6, 4};
  int k = 2;

  int result = findKthLargest(nums, k);

  // Print the result
  cout << "The " << k << "th largest element is: " << result << endl;

  return 0;
}

// Time Complexity: O(N * log k)
// Space Complexity: O(k)