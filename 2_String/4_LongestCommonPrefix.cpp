#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
  if (strs.empty())
    return "";

  string prefix = strs[0];

  for (int i = 1; i < strs.size(); ++i)
  {
    int j = 0;

    while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j])
    {
      ++j;
    }

    prefix = prefix.substr(0, j);

    if (prefix.empty())
      return "";
  }

  return prefix;
}

int main()
{
  vector<string> strs = {"flower", "flow", "flight"};

  cout << "Longest common prefix for strs1: " << longestCommonPrefix(strs) << endl;

  return 0;
}

// Time Complexity = O(n*m)
// Space Complexity = O(1)