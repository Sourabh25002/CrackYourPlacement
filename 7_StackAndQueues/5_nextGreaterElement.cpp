#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
  {
    // Map to store the next greater element for each number in nums2
    unordered_map<int, int> next_greater;
    stack<int> st;

    // Traverse nums2 and fill the map with the next greater elements
    for (int num : nums2)
    {
      while (!st.empty() && st.top() < num)
      {
        next_greater[st.top()] = num;
        st.pop();
      }
      st.push(num);
    }

    // For elements left in the stack, there is no greater element
    while (!st.empty())
    {
      next_greater[st.top()] = -1;
      st.pop();
    }

    // Prepare the result for nums1 using the map
    vector<int> result;
    for (int num : nums1)
    {
      result.push_back(next_greater[num]);
    }

    return result;
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<int> nums1_1 = {4, 1, 2};
  vector<int> nums2_1 = {1, 3, 4, 2};
  vector<int> result1 = sol.nextGreaterElement(nums1_1, nums2_1);
  cout << "Output for Example 1: ";
  for (int num : result1)
  {
    cout << num << " ";
  }
  cout << endl;

  // Example 2
  vector<int> nums1_2 = {2, 4};
  vector<int> nums2_2 = {1, 2, 3, 4};
  vector<int> result2 = sol.nextGreaterElement(nums1_2, nums2_2);
  cout << "Output for Example 2: ";
  for (int num : result2)
  {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}

/*
Time Complexity:
- The time complexity of this solution is O(n + m), where n is the size of nums1 and m is the size of nums2.
  - We traverse nums2 once to build the next_greater map, which takes O(m) time.
  - We then traverse nums1 to build the result vector, which takes O(n) time.

Space Complexity:
- The space complexity is O(m) due to the storage required for the next_greater map and the stack.
  - The map stores the next greater element for each element in nums2.
  - The stack is used to keep track of elements for which we are finding the next greater element.
*/
