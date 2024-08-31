#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Helper function to reverse a substring in place
  void reverseSubstring(string &s, int start, int end)
  {
    while (start < end)
    {
      swap(s[start++], s[end--]);
    }
  }

  // Helper function to trim leading and trailing spaces
  void trimSpaces(string &s)
  {
    int n = s.size();
    int i = 0, j = 0;

    while (j < n)
    {
      while (j < n && s[j] == ' ')
        j++; // skip spaces
      while (j < n && s[j] != ' ')
        s[i++] = s[j++]; // copy word
      while (j < n && s[j] == ' ')
        j++; // skip spaces
      if (j < n)
        s[i++] = ' '; // insert space if not the end
    }

    s.resize(i);
  }

  string reverseWords(string s)
  {
    // Trim leading and trailing spaces and reduce multiple spaces to one
    trimSpaces(s);
    int n = s.size();

    // Reverse the entire string
    reverseSubstring(s, 0, n - 1);

    // Reverse each word in the reversed string
    int start = 0;
    for (int end = 0; end <= n; ++end)
    {
      if (end == n || s[end] == ' ')
      {
        reverseSubstring(s, start, end - 1);
        start = end + 1;
      }
    }

    return s;
  }
};

int main()
{
  Solution sol;

  // Example 1
  string s1 = "the sky is blue";
  cout << "Reversed Words: " << sol.reverseWords(s1) << endl; // Output: "blue is sky the"

  // Example 2
  string s2 = "  hello world  ";
  cout << "Reversed Words: " << sol.reverseWords(s2) << endl; // Output: "world hello"

  // Example 3
  string s3 = "a good   example";
  cout << "Reversed Words: " << sol.reverseWords(s3) << endl; // Output: "example good a"

  return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
