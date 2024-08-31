#include <bits/stdc++.h>
using namespace std;

bool canPermuteToSatisfyK(int k, vector<int> &arr1, vector<int> &arr2)
{
  // Sort arr1 in ascending order
  sort(arr1.begin(), arr1.end());
  // Sort arr2 in descending order
  sort(arr2.begin(), arr2.end(), greater<int>());

  // Check if for all indices, the sum of elements is at least k
  for (size_t i = 0; i < arr1.size(); ++i)
  {
    if (arr1[i] + arr2[i] < k)
    {
      return false;
    }
  }

  return true;
}

int main()
{
  vector<int> arr1_1 = {2, 1, 3};
  vector<int> arr2_1 = {7, 8, 9};
  int k1 = 10;
  cout << (canPermuteToSatisfyK(k1, arr1_1, arr2_1) ? "true" : "false") << endl; // Output: true

  vector<int> arr1_2 = {1, 2, 2, 1};
  vector<int> arr2_2 = {3, 3, 3, 4};
  int k2 = 5;
  cout << (canPermuteToSatisfyK(k2, arr1_2, arr2_2) ? "true" : "false") << endl; // Output: false

  return 0;
}

/*
Time Complexity: O(n * log(n)), due to sorting the arrays.
Space Complexity: O(1), ignoring the space used by the sorting functions.
*/
