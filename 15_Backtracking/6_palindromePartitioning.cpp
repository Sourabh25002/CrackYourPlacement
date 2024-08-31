#include <bits/stdc++.h>
using namespace std;

// Function to check if a string is a palindrome
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

// Backtracking function to find all palindrome partitions
void backtrack(const string &s, int start, vector<string> &current, vector<vector<string>> &result)
{
  if (start >= s.size())
  {
    result.push_back(current);
    return;
  }

  for (int end = start; end < s.size(); ++end)
  {
    if (isPalindrome(s, start, end))
    {
      current.push_back(s.substr(start, end - start + 1));
      backtrack(s, end + 1, current, result);
      current.pop_back(); // Backtrack
    }
  }
}

vector<vector<string>> partition(string s)
{
  vector<vector<string>> result;
  vector<string> current;
  backtrack(s, 0, current, result);
  return result;
}

int main()
{
  string s;
  cin >> s;

  vector<vector<string>> result = partition(s);
  for (const auto &partition : result)
  {
    cout << "[";
    for (size_t i = 0; i < partition.size(); ++i)
    {
      if (i > 0)
        cout << ",";
      cout << "[" << partition[i] << "]";
    }
    cout << "]\n";
  }

  return 0;
}

/*
Time Complexity: O(2^n * n), where n is the length of the string. This is due to the exponential number of possible partitions and checking each substring.
Space Complexity: O(n * 2^n), due to storing all possible partitions and recursion stack.
*/
