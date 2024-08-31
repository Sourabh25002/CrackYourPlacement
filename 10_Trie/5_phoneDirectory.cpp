#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<string>> displayContacts(int n, string contact[], string s)
  {
    vector<vector<string>> result;
    set<string> contactSet(contact, contact + n);

    string prefix = "";
    for (char c : s)
    {
      prefix += c;
      vector<string> matchedContacts;
      for (auto &name : contactSet)
      {
        if (name.find(prefix) == 0)
        {
          matchedContacts.push_back(name);
        }
      }
      if (matchedContacts.empty())
      {
        result.push_back({"0"});
      }
      else
      {
        result.push_back(matchedContacts);
      }
    }
    return result;
  }
};

int main()
{
  int n = 3;
  string contact[] = {"geeikistest", "geeksforgeeks", "geeksfortest"};
  string s = "geeips";

  Solution sol;
  vector<vector<string>> ans = sol.displayContacts(n, contact, s);

  for (auto &list : ans)
  {
    for (auto &name : list)
    {
      cout << name << " ";
    }
    cout << endl;
  }

  return 0;
}

/*
Time Complexity: O(|s| * n * max|contact[i]|)
Space Complexity: O(n * max|contact[i]|)
*/
