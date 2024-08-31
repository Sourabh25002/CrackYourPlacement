#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isNumber(string s)
  {
    int n = s.length();
    bool seenDigit = false, seenDot = false, seenExp = false;
    int signCount = 0;

    for (int i = 0; i < n; ++i)
    {
      char ch = s[i];

      if (isdigit(ch))
      {
        seenDigit = true;
      }
      else if (ch == '+' || ch == '-')
      {
        if (i > 0 && (s[i - 1] != 'e' && s[i - 1] != 'E'))
          return false;
        if (++signCount > 2)
          return false;
      }
      else if (ch == '.')
      {
        if (seenDot || seenExp)
          return false;
        seenDot = true;
      }
      else if (ch == 'e' || ch == 'E')
      {
        if (seenExp || !seenDigit)
          return false;
        seenExp = true;
        seenDigit = false; // Need a digit after the exponent
      }
      else
      {
        return false;
      }
    }

    return seenDigit;
  }
};

int main()
{
  Solution solution;

  string s1 = "0";
  cout << "Output: " << solution.isNumber(s1) << endl;

  string s2 = "e";
  cout << "Output: " << solution.isNumber(s2) << endl;

  string s3 = ".";
  cout << "Output: " << solution.isNumber(s3) << endl;

  string s4 = "2e10";
  cout << "Output: " << solution.isNumber(s4) << endl;

  return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
