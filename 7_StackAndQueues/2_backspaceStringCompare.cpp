#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool backspaceCompare(string s, string t)
  {
    stack<char> st;
    stack<char> p;

    // Process the first string
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == '#')
      {
        if (!st.empty())
        {
          st.pop();
        }
      }
      else
      {
        st.push(s[i]);
      }
    }

    // Process the second string
    for (int i = 0; i < t.size(); i++)
    {
      if (t[i] == '#')
      {
        if (!p.empty())
        {
          p.pop();
        }
      }
      else
      {
        p.push(t[i]);
      }
    }

    // Compare the two stacks
    while (!st.empty() && !p.empty())
    {
      if (st.top() != p.top())
      {
        return false;
      }
      st.pop();
      p.pop();
    }

    // If both stacks are empty, the strings are equal
    return st.empty() && p.empty();
  }
};

int main()
{
  Solution solution;

  // Example 1:
  string s1 = "ab#c";
  string t1 = "ad#c";
  cout << (solution.backspaceCompare(s1, t1) ? "true" : "false") << endl; // Outputs: true

  // Example 2:
  string s2 = "ab##";
  string t2 = "c#d#";
  cout << (solution.backspaceCompare(s2, t2) ? "true" : "false") << endl; // Outputs: true

  // Example 3:
  string s3 = "a#c";
  string t3 = "b";
  cout << (solution.backspaceCompare(s3, t3) ? "true" : "false") << endl; // Outputs: false

  return 0;
}

/*
Time Complexity: O(n + m), where n is the length of string s and m is the length of string t.
- Each character in both strings is processed once, so the time complexity is linear.

Space Complexity: O(n + m) for the extra space used by the stacks.
- The worst case occurs when there are no '#' characters and both strings are pushed entirely onto the stacks.
*/
