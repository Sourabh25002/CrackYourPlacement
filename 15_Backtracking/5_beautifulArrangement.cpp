#include <bits/stdc++.h>
using namespace std;

// Function to count the number of beautiful arrangements
void countArrangementUtil(vector<int> &nums, vector<bool> &used, int index, int &count, int n)
{
  if (index > n)
  {
    count++;
    return;
  }

  for (int i = 1; i <= n; ++i)
  {
    if (!used[i] && (i % index == 0 || index % i == 0))
    {
      used[i] = true;
      countArrangementUtil(nums, used, index + 1, count, n);
      used[i] = false; // Backtrack
    }
  }
}

int countArrangement(int n)
{
  vector<int> nums(n + 1, 0);
  vector<bool> used(n + 1, false);
  int count = 0;
  countArrangementUtil(nums, used, 1, count, n);
  return count;
}

int main()
{
  int n;
  cin >> n;

  cout << countArrangement(n) << endl;

  return 0;
}

/*
Time Complexity: O(n!) due to the permutation generation and checking.
Space Complexity: O(n) for the recursion stack and used array.
*/
