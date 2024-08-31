#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string removeKdigits(string num, int k)
  {
    stack<char> st;
    for (char digit : num)
    {
      while (!st.empty() && k > 0 && st.top() > digit)
      {
        st.pop();
        k--;
      }
      st.push(digit);
    }

    // If k > 0, remove remaining k digits from the end
    while (k > 0)
    {
      st.pop();
      k--;
    }

    // Build the result string
    string result;
    while (!st.empty())
    {
      result += st.top();
      st.pop();
    }
    reverse(result.begin(), result.end());

    // Remove leading zeros
    size_t nonZeroPos = result.find_first_not_of('0');
    if (nonZeroPos == string::npos)
      return "0"; // all zeros case
    return result.substr(nonZeroPos);
  }
};

int main()
{
  Solution solution;

  string num1 = "1432219";
  int k1 = 3;
  cout << "Example 1 Output: " << solution.removeKdigits(num1, k1) << endl; // Output: "1219"

  string num2 = "10200";
  int k2 = 1;
  cout << "Example 2 Output: " << solution.removeKdigits(num2, k2) << endl; // Output: "200"

  string num3 = "10";
  int k3 = 2;
  cout << "Example 3 Output: " << solution.removeKdigits(num3, k3) << endl; // Output: "0"

  return 0;
}

/*
Time Complexity: O(N), where N is the length of the string (for processing digits and managing stack operations).
Space Complexity: O(N), where N is the length of the string (for storing digits in the stack).
*/
