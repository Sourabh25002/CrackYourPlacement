#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string findMaximumNum(string str, int k)
  {
    function<void(int, int)> solve = [&](int index, int k)
    {
      if (k == 0 || index >= str.size())
        return;

      char maxChar = str[index];
      for (int i = index + 1; i < str.size(); ++i)
      {
        if (str[i] > maxChar)
        {
          maxChar = str[i];
        }
      }

      if (maxChar != str[index])
      {
        --k;
        for (int i = str.size() - 1; i >= index; --i)
        {
          if (str[i] == maxChar)
          {
            swap(str[index], str[i]);
            solve(index + 1, k);
            swap(str[index], str[i]);
          }
        }
      }
      else
      {
        solve(index + 1, k);
      }
    };

    solve(0, k);
    return str;
  }
};

int main()
{
  Solution sol;

  string str1 = "1234567";
  int k1 = 4;
  cout << sol.findMaximumNum(str1, k1) << endl; // Output: 7654321

  string str2 = "3435335";
  int k2 = 3;
  cout << sol.findMaximumNum(str2, k2) << endl; // Output: 5543333

  return 0;
}

/*
Time Complexity: O(n! / (n-k)!), where n is the length of the string. This is due to the permutations generated during swaps.
Space Complexity: O(n), where n is the length of the string. This is for the recursion stack and intermediate operations.
*/
