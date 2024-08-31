#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string decodeString(string s)
  {
    stack<int> counts;
    stack<string> result;
    string res = "";
    int i = 0;

    while (i < s.length())
    {
      if (isdigit(s[i]))
      {
        int count = 0;
        while (isdigit(s[i]))
        {
          count = count * 10 + (s[i] - '0');
          i++;
        }
        counts.push(count);
      }
      else if (s[i] == '[')
      {
        result.push(res);
        res = "";
        i++;
      }
      else if (s[i] == ']')
      {
        string temp = result.top();
        result.pop();
        int count = counts.top();
        counts.pop();
        for (int j = 0; j < count; j++)
        {
          temp += res;
        }
        res = temp;
        i++;
      }
      else
      {
        res += s[i];
        i++;
      }
    }
    return res;
  }
};

int main()
{
  Solution sol;
  string s1 = "3[a]2[bc]";
  string s2 = "3[a2[c]]";
  string s3 = "2[abc]3[cd]ef";

  cout << sol.decodeString(s1) << endl; // Output: "aaabcbc"
  cout << sol.decodeString(s2) << endl; // Output: "accaccacc"
  cout << sol.decodeString(s3) << endl; // Output: "abcabccdcdcdef"

  return 0;
}

/*
Time Complexity: O(maxK * n), where maxK is the maximum value of k and n is the length of the string.
Space Complexity: O(m + n), where m is the number of digits in s and n is the length of the string.
*/
