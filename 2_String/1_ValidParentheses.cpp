#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
  stack<char> st;
  unordered_map<char, char> brackets = {{')', '('}, {']', '['}, {'}', '{'}};

  for (char c : s)
  {
    if (c == '(' || c == '[' || c == '{')
    {
      st.push(c);
    }
    else
    {
      if (st.empty() || brackets[c] != st.top())
      {
        return false;
      }
      st.pop();
    }
  }

  return st.empty();
}

int main()
{
  string s = "{[()]}";
  if (isValid(s))
  {
    cout << "The string is valid." << endl;
  }
  else
  {
    cout << "The string is not valid." << endl;
  }
  return 0;
}

// Time Complexity = O(N)
// Space Complexity = O(N)