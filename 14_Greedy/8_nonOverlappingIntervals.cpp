#include <bits/stdc++.h>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
  if (intervals.empty())
    return 0;

  // Sort intervals based on the end time
  sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
       { return a[1] < b[1]; });

  int count = 0;
  int lastEnd = intervals[0][1];

  for (int i = 1; i < intervals.size(); ++i)
  {
    if (intervals[i][0] < lastEnd)
    { // Overlapping interval
      ++count;
    }
    else
    {
      lastEnd = intervals[i][1];
    }
  }

  return count;
}

int main()
{
  int n;
  cin >> n;

  vector<vector<int>> intervals(n, vector<int>(2));

  for (int i = 0; i < n; ++i)
  {
    cin >> intervals[i][0] >> intervals[i][1];
  }

  cout << eraseOverlapIntervals(intervals) << endl;

  return 0;
}

/*
Time Complexity: O(n log n), where n is the number of intervals, due to sorting.
Space Complexity: O(1), as we are using only a few extra variables.
*/
