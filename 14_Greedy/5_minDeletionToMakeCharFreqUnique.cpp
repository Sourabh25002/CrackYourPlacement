#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minDeletions(string s)
  {
    unordered_map<char, int> freq;
    for (char ch : s)
    {
      freq[ch]++;
    }

    unordered_set<int> uniqueFreq;
    int deletions = 0;

    for (const auto &entry : freq)
    {
      int count = entry.second;
      while (count > 0 && uniqueFreq.count(count))
      {
        count--;
        deletions++;
      }
      uniqueFreq.insert(count);
    }

    return deletions;
  }
};

int main()
{
  Solution solution;

  string s1 = "aab";
  cout << "Example 1 Output: " << solution.minDeletions(s1) << endl; // Output: 0

  string s2 = "aaabbbcc";
  cout << "Example 2 Output: " << solution.minDeletions(s2) << endl; // Output: 2

  string s3 = "ceabaacb";
  cout << "Example 3 Output: " << solution.minDeletions(s3) << endl; // Output: 2

  return 0;
}

/*
Time Complexity: O(N), where N is the length of the string (for counting frequencies and processing deletions).
Space Complexity: O(1), as the space used for frequencies and unique frequencies is constant with respect to the number of unique characters.
*/
