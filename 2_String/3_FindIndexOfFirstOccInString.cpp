#include <bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle)
{
  int found = haystack.find(needle);

  if (found != string::npos)
  {
    return found;
  }
  else
  {
    return -1;
  }
}

int main()
{
  string haystack = "hello";
  string needle = "ll";
  int index = strStr(haystack, needle);

  if (index != -1)
  {
    cout << "The substring \"" << needle << "\" is found at index " << index << " in the string \"" << haystack << "\"." << endl;
  }
  else
  {
    cout << "The substring \"" << needle << "\" is not found in the string \"" << haystack << "\"." << endl;
  }

  return 0;
}

// Time Complexity = O(n * m)
// Space Complexity = O(1)
