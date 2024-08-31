#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k)
  {
    vector<int> res; // Vector to store the result
    deque<int> dq;   // Deque to store the indices of potential maximum elements

    // Loop through each element in the array
    for (int idx = 0; idx < nums.size(); idx++)
    {
      int num = nums[idx];

      // Remove elements from the back of the deque that are less than the current element
      // because they cannot be the maximum if we encounter a larger number
      while (!dq.empty() && nums[dq.back()] < num)
      {
        dq.pop_back();
      }
      // Add the current element's index to the deque
      dq.push_back(idx);

      // Remove elements from the front of the deque that are out of the bounds of the current window
      if (dq.front() <= idx - k)
      {
        dq.pop_front();
      }

      // Once we have processed at least 'k' elements, the element at the front of the deque is the maximum
      // for the current window
      if (idx >= k - 1)
      {
        res.push_back(nums[dq.front()]);
      }
    }

    return res;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;

  vector<int> result = sol.maxSlidingWindow(nums, k);

  cout << "Max sliding window: ";
  for (int n : result)
  {
    cout << n << " ";
  }
  cout << endl;

  return 0;
}

/*
Time Complexity:
- The overall time complexity is O(n), where n is the number of elements in the input array `nums`.
- Each element is pushed and popped from the deque at most once, which makes it linear.

Space Complexity:
- The space complexity is O(k), which is the maximum size of the deque.
- The deque stores at most k indices corresponding to elements in the current window.
*/
