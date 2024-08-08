#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void backtrack(vector<int> &arr, vector<vector<int>> &result, vector<int> &current, vector<bool> &used)
  {
    if (current.size() == arr.size())
    {
      result.push_back(current);
      return;
    }

    for (int i = 0; i < arr.size(); i++)
    {
      // Skip duplicates
      if (used[i] || (i > 0 && arr[i] == arr[i - 1] && !used[i - 1]))
      {
        continue;
      }

      used[i] = true;
      current.push_back(arr[i]);
      backtrack(arr, result, current, used);
      current.pop_back();
      used[i] = false;
    }
  }

  vector<vector<int>> uniquePerms(vector<int> &arr, int n)
  {
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> used(n, false);

    // Sort the array to handle duplicates
    sort(arr.begin(), arr.end());

    // Call the backtracking function
    backtrack(arr, result, current, used);

    return result;
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<int> arr1 = {1, 2, 1};
  vector<vector<int>> result1 = sol.uniquePerms(arr1, arr1.size());
  for (const auto &perm : result1)
  {
    for (int num : perm)
    {
      cout << num << " ";
    }
    cout << endl;
  }

  // Example 2
  vector<int> arr2 = {4, 5};
  vector<vector<int>> result2 = sol.uniquePerms(arr2, arr2.size());
  for (const auto &perm : result2)
  {
    for (int num : perm)
    {
      cout << num << " ";
    }
    cout << endl;
  }

  return 0;
}

// Time Complexity: O(n * n!)
// Space Complexity: O(n)