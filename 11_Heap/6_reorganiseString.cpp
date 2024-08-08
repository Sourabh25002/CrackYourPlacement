#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string reorganizeString(string s)
  {
    unordered_map<char, int> freq;
    priority_queue<pair<int, char>> maxHeap;

    // Count the frequency of each character
    for (char c : s)
    {
      freq[c]++;
    }

    // Push all characters and their frequencies into the max heap
    for (const auto &it : freq)
    {
      maxHeap.push({it.second, it.first});
    }

    string result;
    pair<int, char> prev = {0, '#'}; // Initialize previous character

    while (!maxHeap.empty())
    {
      pair<int, char> top = maxHeap.top();
      maxHeap.pop();

      // Append the current character to the result
      result += top.second;

      // If there was a previous character waiting to be added back to the heap
      if (prev.first > 0)
      {
        maxHeap.push(prev);
      }

      // Update the count of the current character and set it as previous
      prev = {top.first - 1, top.second};
    }

    // Check if the result length matches the original string length
    return result.size() == s.size() ? result : "";
  }
};

int main()
{
  // Example test cases
  Solution sol;

  string s1 = "aab";
  cout << "Reorganized string for \"" << s1 << "\": " << sol.reorganizeString(s1) << endl;

  string s2 = "aaab";
  cout << "Reorganized string for \"" << s2 << "\": " << sol.reorganizeString(s2) << endl;

  return 0;
}

// Time Complexity: O(N log C)
// Space Complexity: O(N)