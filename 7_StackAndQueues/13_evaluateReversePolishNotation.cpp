#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int evalRPN(vector<string> &tokens)
  {
    stack<int> st;

    for (const string &token : tokens)
    {
      if (token == "+" || token == "-" || token == "*" || token == "/")
      {
        int b = st.top();
        st.pop();
        int a = st.top();
        st.pop();
        if (token == "+")
          st.push(a + b);
        else if (token == "-")
          st.push(a - b);
        else if (token == "*")
          st.push(a * b);
        else if (token == "/")
          st.push(a / b);
      }
      else
      {
        st.push(stoi(token)); // Convert string to integer and push to stack
      }
    }

    return st.top(); // The result is the last element in the stack
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<string> tokens1 = {"2", "1", "+", "3", "*"};
  cout << "Example 1 Output: " << sol.evalRPN(tokens1) << endl;

  // Example 2
  vector<string> tokens2 = {"4", "13", "5", "/", "+"};
  cout << "Example 2 Output: " << sol.evalRPN(tokens2) << endl;

  // Example 3
  vector<string> tokens3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
  cout << "Example 3 Output: " << sol.evalRPN(tokens3) << endl;

  return 0;
}

/*
Time Complexity: O(n) where n is the number of tokens. Each token is processed once.

Space Complexity: O(n) in the worst case for the stack storage.
*/
