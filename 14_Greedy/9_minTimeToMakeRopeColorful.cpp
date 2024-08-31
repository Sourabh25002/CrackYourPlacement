#include <bits/stdc++.h>
using namespace std;

int minCost(string colors, vector<int> &neededTime)
{
  int totalCost = 0;
  int n = colors.size();

  for (int i = 0; i < n; ++i)
  {
    if (i > 0 && colors[i] == colors[i - 1])
    {
      // Add the cost of removing the balloon with the smaller needed time
      totalCost += min(neededTime[i], neededTime[i - 1]);
      // Update neededTime of the previous balloon to be the maximum of the two
      neededTime[i] = max(neededTime[i], neededTime[i - 1]);
    }
  }

  return totalCost;
}

int main()
{
  string colors;
  int n;

  cin >> colors;
  cin >> n;

  vector<int> neededTime(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> neededTime[i];
  }

  cout << minCost(colors, neededTime) << endl;

  return 0;
}

/*
Time Complexity: O(n), where n is the length of the colors string, as we are iterating through the string once.
Space Complexity: O(1), as we are using only a few extra variables.
*/
