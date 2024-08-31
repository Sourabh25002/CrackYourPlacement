#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> mostCompetitive(vector<int> &nums, int k)
  {
    vector<int> stack;
    int n = nums.size();

    for (int i = 0; i < n; ++i)
    {
      // Ensure that the stack can hold the remaining elements
      while (!stack.empty() && stack.back() > nums[i] && stack.size() - 1 + n - i >= k)
        stack.pop_back();

      // Add the current element if the stack has less than k elements
      if (stack.size() < k)
        stack.push_back(nums[i]);
    }

    return stack;
  }
};

int main()
{
  Solution sol;
  vector<int> nums1 = {3, 5, 2, 6};
  int k1 = 2;
  vector<int> result1 = sol.mostCompetitive(nums1, k1);

  vector<int> nums2 = {2, 4, 3, 3, 5, 4, 9, 6};
  int k2 = 4;
  vector<int> result2 = sol.mostCompetitive(nums2, k2);

  // Output results
  cout << "Most competitive subsequence for nums1: ";
  for (int num : result1)
  {
    cout << num << " ";
  }
  cout << endl;

  cout << "Most competitive subsequence for nums2: ";
  for (int num : result2)
  {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}

/*
Time Complexity:
- The algorithm iterates through the array once (O(n)).
- The while loop inside the iteration may cause elements to be popped, but each element is pushed and popped at most once.
- Overall time complexity is O(n).

Space Complexity:
- The space used is primarily for the stack, which in the worst case can store k elements.
- Therefore, the space complexity is O(k).
*/
