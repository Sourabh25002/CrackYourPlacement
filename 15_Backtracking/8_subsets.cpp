#include <bits/stdc++.h>
using namespace std;

// Helper function to generate subsets
void backtrack(vector<int> &nums, vector<vector<int>> &result, vector<int> &current, int start)
{
  result.push_back(current);

  for (int i = start; i < nums.size(); ++i)
  {
    current.push_back(nums[i]);
    backtrack(nums, result, current, i + 1);
    current.pop_back();
  }
}

vector<vector<int>> subsets(vector<int> &nums)
{
  vector<vector<int>> result;
  vector<int> current;
  backtrack(nums, result, current, 0);
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

  vector<vector<int>> result = subsets(nums);
  for (const auto &subset : result)
  {
    cout << "[";
    for (size_t i = 0; i < subset.size(); ++i)
    {
      if (i > 0)
        cout << ",";
      cout << subset[i];
    }
    cout << "]\n";
  }

  return 0;
}

/*
Time Complexity: O(2^n * n), where n is the length of the input array. This is due to generating all possible subsets and handling each subset.
Space Complexity: O(2^n * n), where n is the length of the input array. This is due to storing all subsets and their elements.
*/
