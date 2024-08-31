#include <bits/stdc++.h>
using namespace std;

// Helper function for generating permutations
void backtrack(vector<int> &nums, vector<vector<int>> &result, vector<int> &current, vector<bool> &used)
{
  if (current.size() == nums.size())
  {
    result.push_back(current);
    return;
  }

  for (int i = 0; i < nums.size(); ++i)
  {
    if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]))
    {
      continue;
    }
    used[i] = true;
    current.push_back(nums[i]);
    backtrack(nums, result, current, used);
    current.pop_back();
    used[i] = false;
  }
}

vector<vector<int>> permuteUnique(vector<int> &nums)
{
  vector<vector<int>> result;
  vector<int> current;
  vector<bool> used(nums.size(), false);
  sort(nums.begin(), nums.end()); // Sort to handle duplicates
  backtrack(nums, result, current, used);
  return result;
}

int main()
{
  vector<int> nums;
  int n, value;
  cin >> n;

  for (int i = 0; i < n; ++i)
  {
    cin >> value;
    nums.push_back(value);
  }

  vector<vector<int>> result = permuteUnique(nums);
  for (const auto &perm : result)
  {
    cout << "[";
    for (size_t i = 0; i < perm.size(); ++i)
    {
      if (i > 0)
        cout << ",";
      cout << perm[i];
    }
    cout << "]\n";
  }

  return 0;
}

/*
Time Complexity: O(n! * n), where n is the length of the input array. This is due to generating all permutations and handling duplicates.
Space Complexity: O(n * n!), where n is the length of the input array. This is due to storing all unique permutations.
*/
