#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> palindromePairs(vector<string> &words)
  {
    unordered_map<string, int> wordMap;
    vector<vector<int>> result;

    for (int i = 0; i < words.size(); ++i)
    {
      string reversedWord = words[i];
      reverse(reversedWord.begin(), reversedWord.end());
      wordMap[reversedWord] = i;
    }

    if (wordMap.find("") != wordMap.end())
    {
      int blankIndex = wordMap[""];
      for (int i = 0; i < words.size(); ++i)
      {
        if (i != blankIndex && isPalindrome(words[i]))
        {
          result.push_back({blankIndex, i});
          result.push_back({i, blankIndex});
        }
      }
    }

    for (int i = 0; i < words.size(); ++i)
    {
      for (int j = 0; j < words[i].size(); ++j)
      {
        string left = words[i].substr(0, j);
        string right = words[i].substr(j);

        if (wordMap.find(left) != wordMap.end() && isPalindrome(right) && wordMap[left] != i)
        {
          result.push_back({i, wordMap[left]});
        }

        if (wordMap.find(right) != wordMap.end() && isPalindrome(left) && wordMap[right] != i)
        {
          result.push_back({wordMap[right], i});
        }
      }
    }

    return result;
  }

  bool isPalindrome(const string &s)
  {
    int left = 0, right = s.size() - 1;
    while (left < right)
    {
      if (s[left++] != s[right--])
      {
        return false;
      }
    }
    return true;
  }
};

int main()
{
  Solution sol;
  vector<string> words1 = {"abcd", "dcba", "lls", "s", "sssll"};
  vector<string> words2 = {"bat", "tab", "cat"};
  vector<string> words3 = {"a", ""};

  vector<vector<int>> result1 = sol.palindromePairs(words1);
  vector<vector<int>> result2 = sol.palindromePairs(words2);
  vector<vector<int>> result3 = sol.palindromePairs(words3);

  for (auto &pair : result1)
  {
    cout << "[" << pair[0] << "," << pair[1] << "] ";
  }
  cout << endl;

  for (auto &pair : result2)
  {
    cout << "[" << pair[0] << "," << pair[1] << "] ";
  }
  cout << endl;

  for (auto &pair : result3)
  {
    cout << "[" << pair[0] << "," << pair[1] << "] ";
  }
  cout << endl;

  return 0;
}

/*
Time Complexity: O(sum of words[i].length)
Space Complexity: O(n)
*/
