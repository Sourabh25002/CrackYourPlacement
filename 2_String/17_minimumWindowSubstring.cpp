#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string minWindow(string s, string t)
  {
    if (t.size() > s.size())
      return "";

    unordered_map<char, int> t_map, window_map;
    for (char c : t)
      t_map[c]++;

    int have = 0, need = t_map.size();
    int left = 0, right = 0, minLen = INT_MAX, start = 0;

    while (right < s.size())
    {
      char c = s[right];
      window_map[c]++;

      if (t_map.find(c) != t_map.end() && window_map[c] == t_map[c])
      {
        have++;
      }

      while (have == need)
      {
        if (right - left + 1 < minLen)
        {
          minLen = right - left + 1;
          start = left;
        }

        window_map[s[left]]--;
        if (t_map.find(s[left]) != t_map.end() && window_map[s[left]] < t_map[s[left]])
        {
          have--;
        }
        left++;
      }
      right++;
    }

    return minLen == INT_MAX ? "" : s.substr(start, minLen);
  }
};

int main()
{
  Solution solution;

  string s1 = "ADOBECODEBANC", t1 = "ABC";
  cout << "Input: s = \"" << s1 << "\", t = \"" << t1 << "\"\nOutput: \"" << solution.minWindow(s1, t1) << "\"" << endl;

  string s2 = "a", t2 = "a";
  cout << "Input: s = \"" << s2 << "\", t = \"" << t2 << "\"\nOutput: \"" << solution.minWindow(s2, t2) << "\"" << endl;

  string s3 = "a", t3 = "aa";
  cout << "Input: s = \"" << s3 << "\", t = \"" << t3 << "\"\nOutput: \"" << solution.minWindow(s3, t3) << "\"" << endl;

  return 0;
}

/*
Time Complexity: O(m + n) - where m is the length of string s and n is the length of string t.
Space Complexity: O(m + n) - for storing the frequency maps.
*/
