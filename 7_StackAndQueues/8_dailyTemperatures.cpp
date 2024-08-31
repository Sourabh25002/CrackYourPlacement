#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> dailyTemperatures(vector<int> &temperatures)
  {
    stack<int> st;                           // Stack to store indices of temperatures array
    vector<int> res(temperatures.size(), 0); // Result vector initialized with 0s

    for (int i = 0; i < temperatures.size(); i++)
    {
      // Check if the current temperature is greater than the temperature at index stored at the top of the stack
      while (!st.empty() && temperatures[i] > temperatures[st.top()])
      {
        int idx = st.top();
        st.pop();           // Pop the top index from the stack
        res[idx] = i - idx; // Calculate the difference in days
      }
      st.push(i); // Push the current index onto the stack
    }

    return res;
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<int> temperatures1 = {73, 74, 75, 71, 69, 72, 76, 73};
  vector<int> result1 = sol.dailyTemperatures(temperatures1);
  for (int val : result1)
    cout << val << " ";
  cout << endl; // Output: 1 1 4 2 1 1 0 0

  // Example 2
  vector<int> temperatures2 = {30, 40, 50, 60};
  vector<int> result2 = sol.dailyTemperatures(temperatures2);
  for (int val : result2)
    cout << val << " ";
  cout << endl; // Output: 1 1 1 0

  // Example 3
  vector<int> temperatures3 = {30, 60, 90};
  vector<int> result3 = sol.dailyTemperatures(temperatures3);
  for (int val : result3)
    cout << val << " ";
  cout << endl; // Output: 1 1 0

  return 0;
}

/*
Time Complexity:
- The time complexity of this solution is O(n), where n is the number of elements in the temperatures array. Each element is pushed and popped from the stack at most once.

Space Complexity:
- The space complexity is O(n), where n is the size of the temperatures array. This is due to the additional space used by the stack and the result vector.
*/
