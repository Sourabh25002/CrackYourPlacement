#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string removeDuplicates(string s, int k)
  {
    // Stack to store pairs of characters and their consecutive counts
    stack<pair<char, int>> st;

    // Traverse through the string
    for (char ch : s)
    {
      // If the stack is not empty and the top character is the same as the current one
      if (!st.empty() && st.top().first == ch)
      {
        st.top().second++;
        // If the count reaches k, we pop the top
        if (st.top().second == k)
        {
          st.pop();
        }
      }
      else
      {
        // If it's a new character, push it onto the stack with count 1
        st.push({ch, 1});
      }
    }

    // Reconstruct the string from the stack
    string result = "";
    while (!st.empty())
    {
      result.append(st.top().second, st.top().first);
      st.pop();
    }

    // The result needs to be reversed because we build it backwards from the stack
    reverse(result.begin(), result.end());
    return result;
  }
};

int main()
{
  Solution sol;

  // Example 1
  string s1 = "abcd";
  int k1 = 2;
  cout << "Result: " << sol.removeDuplicates(s1, k1) << endl; // Expected Output: "abcd"

  // Example 2
  string s2 = "deeedbbcccbdaa";
  int k2 = 3;
  cout << "Result: " << sol.removeDuplicates(s2, k2) << endl; // Expected Output: "aa"

  // Example 3
  string s3 = "pbbcggttciiippooaais";
  int k3 = 2;
  cout << "Result: " << sol.removeDuplicates(s3, k3) << endl; // Expected Output: "ps"

  return 0;
}

/*
Time Complexity: O(N), where N is the length of the string `s`. Each character is pushed and popped from the stack at most once.

Space Complexity: O(N), where N is the length of the string `s`. In the worst case, the stack may contain all characters of the string.
*/
