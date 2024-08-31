#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int mctFromLeafValues(vector<int> &arr)
  {
    int res = 0;
    stack<int> st;

    // Traverse each element in the array
    for (int num : arr)
    {
      // While the current element is greater than the top of the stack,
      // pop the stack and calculate the product for merging
      while (!st.empty() && st.top() <= num)
      {
        int mid = st.top();
        st.pop();
        if (st.empty())
        {
          res += mid * num;
        }
        else
        {
          res += mid * min(st.top(), num);
        }
      }
      st.push(num);
    }

    // Merge the remaining elements in the stack
    while (st.size() > 1)
    {
      int top = st.top();
      st.pop();
      res += top * st.top();
    }

    return res;
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<int> arr1 = {6, 2, 4};
  cout << sol.mctFromLeafValues(arr1) << endl; // Output: 32

  // Example 2
  vector<int> arr2 = {4, 11};
  cout << sol.mctFromLeafValues(arr2) << endl; // Output: 44

  return 0;
}

/*
Time Complexity: O(n) where n is the length of the array.
- Each element is pushed and popped from the stack at most once.

Space Complexity: O(n) where n is the length of the array.
- This space is used by the stack.
*/
