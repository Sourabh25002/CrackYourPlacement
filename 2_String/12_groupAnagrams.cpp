#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    unordered_map<string, vector<string>> anagrams;
    for (string s : strs)
    {
      string key = s;
      sort(key.begin(), key.end());
      anagrams[key].push_back(s);
    }

    vector<vector<string>> result;
    for (auto &pair : anagrams)
    {
      result.push_back(pair.second);
    }

    return result;
  }
};

int main()
{
  Solution solution;
  vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<vector<string>> result1 = solution.groupAnagrams(strs1);
  for (const auto &group : result1)
  {
    for (const auto &word : group)
    {
      cout << word << " ";
    }
    cout << endl;
  }

  vector<string> strs2 = {""};
  vector<vector<string>> result2 = solution.groupAnagrams(strs2);
  for (const auto &group : result2)
  {
    for (const auto &word : group)
    {
      cout << word << " ";
    }
    cout << endl;
  }

  vector<string> strs3 = {"a"};
  vector<vector<string>> result3 = solution.groupAnagrams(strs3);
  for (const auto &group : result3)
  {
    for (const auto &word : group)
    {
      cout << word << " ";
    }
    cout << endl;
  }

  return 0;
}

/*
Time Complexity: O(N * K log K) where N is the number of strings and K is the maximum length of a string.
Space Complexity: O(N * K)
*/
