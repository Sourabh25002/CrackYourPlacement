#include <bits/stdc++.h>
using namespace std;

// Function to check if it's possible to place cows with at least 'dist' minimum distance
bool canPlaceCows(const vector<int> &stalls, int N, int C, int dist)
{
  int count = 1;           // First cow placed in the first stall
  int lastPos = stalls[0]; // Position of the last placed cow

  for (int i = 1; i < N; ++i)
  {
    if (stalls[i] - lastPos >= dist)
    {
      ++count;
      lastPos = stalls[i];
      if (count == C)
      {
        return true;
      }
    }
  }

  return false;
}

// Function to find the largest minimum distance
int largestMinimumDistance(vector<int> &stalls, int N, int C)
{
  sort(stalls.begin(), stalls.end());

  int low = 1;                          // Minimum possible distance
  int high = stalls[N - 1] - stalls[0]; // Maximum possible distance
  int result = 0;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    if (canPlaceCows(stalls, N, C, mid))
    {
      result = mid; // This distance is possible, try for a larger distance
      low = mid + 1;
    }
    else
    {
      high = mid - 1; // This distance is not possible, try a smaller distance
    }
  }

  return result;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--)
  {
    int N, C;
    cin >> N >> C;
    vector<int> stalls(N);
    for (int i = 0; i < N; ++i)
    {
      cin >> stalls[i];
    }
    cout << largestMinimumDistance(stalls, N, C) << endl;
  }

  return 0;
}

/*
Time Complexity: O(N log(maxDistance)), where N is the number of stalls and maxDistance is the range of stall positions.
Space Complexity: O(N), for storing the stall positions.
*/
