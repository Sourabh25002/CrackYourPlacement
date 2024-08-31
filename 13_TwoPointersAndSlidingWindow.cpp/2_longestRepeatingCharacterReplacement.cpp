#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int characterReplacement(string s, int k)
  {
    int n = s.length();
    vector<int> count(26, 0); // Count of each character in the current window
    int max_count = 0;        // Maximum frequency of a single character in the current window
    int start = 0, max_len = 0;

    for (int end = 0; end < n; ++end)
    {
      count[s[end] - 'A']++;
      max_count = max(max_count, count[s[end] - 'A']);

      // If the current window size minus the max_count character exceeds k, shrink the window
      if (end - start + 1 - max_count > k)
      {
        count[s[start] - 'A']--;
        start++;
      }

      max_len = max(max_len, end - start + 1);
    }

    return max_len;
  }
};

int main()
{
  Solution sol;

  string s1 = "ABAB";
  int k1 = 2;
  cout << "Example 1 Output: " << sol.characterReplacement(s1, k1) << endl; // Output: 4

  string s2 = "AABABBA";
  int k2 = 1;
  cout << "Example 2 Output: " << sol.characterReplacement(s2, k2) << endl; // Output: 4

  return 0;
}

/*
Time Complexity: O(n), where n is the length of the string.
Space Complexity: O(1), as the size of the count array is constant (26).
*/
