#include <bits/stdc++.h>
using namespace std;

// Function to check if a given string is a palindrome
bool isPalindrome(const string &s, int start, int end)
{
  while (start < end)
  {
    if (s[start] != s[end])
      return false;
    start++;
    end--;
  }
  return true;
}

// Recursive function to find all palindromic partitions
void findPartitions(const string &s, int start, vector<string> &current, vector<vector<string>> &result)
{
  if (start >= s.length())
  {
    result.push_back(current);
    return;
  }

  for (int end = start; end < s.length(); ++end)
  {
    if (isPalindrome(s, start, end))
    {
      current.push_back(s.substr(start, end - start + 1));
      findPartitions(s, end + 1, current, result);
      current.pop_back(); // Backtrack
    }
  }
}

// Function to find all possible palindromic partitions of the string
vector<vector<string>> allPalindromicPerms(const string &s)
{
  vector<vector<string>> result;
  vector<string> current;
  findPartitions(s, 0, current, result);
  return result;
}

int main()
{
  // Example 1
  string s1 = "geeks";
  vector<vector<string>> result1 = allPalindromicPerms(s1);
  cout << "Partitions for \"" << s1 << "\":" << endl;
  for (const auto &partition : result1)
  {
    for (const auto &str : partition)
    {
      cout << str << " ";
    }
    cout << endl;
  }

  // Example 2
  string s2 = "madam";
  vector<vector<string>> result2 = allPalindromicPerms(s2);
  cout << "Partitions for \"" << s2 << "\":" << endl;
  for (const auto &partition : result2)
  {
    for (const auto &str : partition)
    {
      cout << str << " ";
    }
    cout << endl;
  }

  return 0;
}

/*
Time Complexity: O(N * 2^N), where N is the length of the string. The algorithm explores all possible partitions and checks each substring for being a palindrome.
Space Complexity: O(N^2), where N is the length of the string. The space is used for storing intermediate results and palindromic substrings.
*/
