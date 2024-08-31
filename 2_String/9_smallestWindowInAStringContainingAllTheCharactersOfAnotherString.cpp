#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string smallestWindow(string S, string P)
  {
    unordered_map<char, int> mapP;
    unordered_map<char, int> mapS;

    // Frequency map for characters in P
    for (char c : P)
    {
      mapP[c]++;
    }

    int count = 0, start = 0, minLength = INT_MAX;
    int startIndex = -1;

    for (int end = 0; end < S.size(); end++)
    {
      mapS[S[end]]++;

      // Check if the current character added is useful (exists in P and still required)
      if (mapP[S[end]] != 0 && mapS[S[end]] <= mapP[S[end]])
      {
        count++;
      }

      // When all characters are matched
      while (count == P.size())
      {
        // Update minimum length
        if (end - start + 1 < minLength)
        {
          minLength = end - start + 1;
          startIndex = start;
        }

        // Try to shrink the window from the left
        mapS[S[start]]--;
        if (mapP[S[start]] != 0 && mapS[S[start]] < mapP[S[start]])
        {
          count--;
        }
        start++;
      }
    }

    // If no valid window was found, return "-1"
    if (startIndex == -1)
    {
      return "-1";
    }

    // Return the smallest window
    return S.substr(startIndex, minLength);
  }
};

int main()
{
  Solution sol;

  // Example 1
  string S1 = "timetopractice";
  string P1 = "toc";
  cout << "Smallest Window: " << sol.smallestWindow(S1, P1) << endl; // Output: "toprac"

  // Example 2
  string S2 = "zoomlazapzo";
  string P2 = "oza";
  cout << "Smallest Window: " << sol.smallestWindow(S2, P2) << endl; // Output: "apzo"

  return 0;
}

/*
Time Complexity: O(|S|)
Space Complexity: O(|P|)
*/
