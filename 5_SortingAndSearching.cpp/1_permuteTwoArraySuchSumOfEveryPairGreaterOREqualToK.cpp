#include <bits/stdc++.h>
using namespace std;

bool canPermuteArrays(vector<int> &a, vector<int> &b, int k)
{
  sort(a.begin(), a.end());                 // Sort array a in ascending order
  sort(b.begin(), b.end(), greater<int>()); // Sort array b in descending order

  for (int i = 0; i < a.size(); ++i)
  {
    if (a[i] + b[i] < k)
    {
      return false; // If any pair does not satisfy the condition, return false
    }
  }

  return true; // If all pairs satisfy the condition, return true
}

int main()
{
  vector<int> a = {2, 1, 3};
  vector<int> b = {7, 8, 9};
  int k = 10;

  if (canPermuteArrays(a, b, k))
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }

  return 0;
}

/*
Time Complexity: O(n log n), where n is the number of elements in the arrays. This is due to the sorting operations.
Space Complexity: O(1), assuming sorting is done in-place.
*/
