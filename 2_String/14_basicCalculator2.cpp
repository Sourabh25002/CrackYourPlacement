#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int calculate(string s)
  {
    int n = s.length();
    int currentNumber = 0;
    char operation = '+';
    stack<int> stk;

    for (int i = 0; i < n; i++)
    {
      char ch = s[i];

      if (isdigit(ch))
      {
        currentNumber = currentNumber * 10 + (ch - '0');
      }

      if (!isdigit(ch) && !isspace(ch) || i == n - 1)
      {
        if (operation == '+')
        {
          stk.push(currentNumber);
        }
        else if (operation == '-')
        {
          stk.push(-currentNumber);
        }
        else if (operation == '*')
        {
          int top = stk.top();
          stk.pop();
          stk.push(top * currentNumber);
        }
        else if (operation == '/')
        {
          int top = stk.top();
          stk.pop();
          stk.push(top / currentNumber);
        }
        operation = ch;
        currentNumber = 0;
      }
    }

    int result = 0;
    while (!stk.empty())
    {
      result += stk.top();
      stk.pop();
    }

    return result;
  }
};

int main()
{
  Solution solution;

  string s1 = "3+2*2";
  cout << "Output: " << solution.calculate(s1) << endl;

  string s2 = " 3/2 ";
  cout << "Output: " << solution.calculate(s2) << endl;

  string s3 = " 3+5 / 2 ";
  cout << "Output: " << solution.calculate(s3) << endl;

  return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
