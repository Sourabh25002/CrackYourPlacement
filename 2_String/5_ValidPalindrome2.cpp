#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string &s, int left, int right)
{
  while (left < right)
  {
    if (s[left] != s[right])
      return false;
    ++left;
    --right;
  }
  return true;
}

bool validPalindrome(string s)
{
  int left = 0, right = s.size() - 1;

  while (left < right)
  {
    if (s[left] != s[right])
    {

      return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
    }
    ++left;
    --right;
  }

  return true;
}

int main()
{

  string s = "abca";

  cout << "Input: " << s << ", Output: " << validPalindrome(s) << endl;

  return 0;
}

// Time Complexity = O(n)
// Space Complexity = O(1)