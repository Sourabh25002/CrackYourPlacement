#include <bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m)
{
  if (m == 0 || n == 0 || n < m)
    return -1;

  sort(a.begin(), a.end());

  long long minDiff = LLONG_MAX;

  for (long long i = 0; i + m - 1 < n; ++i)
  {
    long long currentDiff = a[i + m - 1] - a[i];
    minDiff = min(minDiff, currentDiff);
  }

  return minDiff;
}

int main()
{

  vector<long long> a1 = {3, 4, 1, 9, 56, 7, 9, 12};
  long long n1 = 8, m1 = 5;

  cout << "Minimum difference is: " << findMinDiff(a1, n1, m1) << endl;

  vector<long long> a2 = {7, 3, 2, 4, 9, 12, 56};
  long long n2 = 7, m2 = 3;

  cout << "Minimum difference is: " << findMinDiff(a2, n2, m2) << endl;

  return 0;
}

// Time Complexity = O(NlogN)
// Space Complexity = O(1)