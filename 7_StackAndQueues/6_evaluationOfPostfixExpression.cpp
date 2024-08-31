#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Function to evaluate a postfix expression.
  int evaluatePostfix(string s)
  {
    stack<int> st; // Stack to hold the operands

    // Iterate through each character in the string
    for (int i = 0; i < s.length(); i++)
    {
      // If the character is a digit, convert it to integer and push to stack
      if (isdigit(s[i]))
      {
        int x = s[i] - '0'; // Convert char to int
        st.push(x);
      }
      // If the character is an operator, pop two operands from the stack and apply the operator
      else
      {
        int y = st.top();
        st.pop();
        int x = st.top();
        st.pop();

        // Apply the operator
        if (s[i] == '*')
        {
          st.push(x * y);
        }
        else if (s[i] == '/')
        {
          st.push(x / y);
        }
        else if (s[i] == '+')
        {
          st.push(x + y);
        }
        else if (s[i] == '-')
        {
          st.push(x - y);
        }
      }
    }

    // The final result is the only element remaining in the stack
    return st.top();
  }
};

int main()
{
  Solution sol;

  // Example 1
  string s1 = "231*+9-";
  cout << "Output for Example 1: " << sol.evaluatePostfix(s1) << endl; // Output: -4

  // Example 2
  string s2 = "123+*8-";
  cout << "Output for Example 2: " << sol.evaluatePostfix(s2) << endl; // Output: -3

  return 0;
}

/*
Time Complexity:
- The time complexity of this function is O(|S|), where |S| is the length of the input string. Each character in the string is processed exactly once.
- Operations within the loop, including stack operations and arithmetic operations, are O(1).

Space Complexity:
- The space complexity is O(|S|) in the worst case, where |S| is the length of the input string. This is because, in the worst case, all characters could be operands and need to be stored in the stack.
*/
