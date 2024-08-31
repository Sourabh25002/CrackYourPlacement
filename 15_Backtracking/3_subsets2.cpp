#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void backtrack(vector<vector<int>> &result, vector<int> &temp, vector<int> &nums, int start)
  {
    result.push_back(temp);

    for (int i = start; i < nums.size(); ++i)
    {
      // Skip duplicates
      if (i > start && nums[i] == nums[i - 1])
        continue;

      temp.push_back(nums[i]);
      backtrack(result, temp, nums, i + 1);
      temp.pop_back(); // Remove the last element for the next iteration
    }
  }

  vector<vector<int>> subsetsWithDup(vector<int> &nums)
  {
    sort(nums.begin(), nums.end()); // Sort to handle duplicates
    vector<vector<int>> result;
    vector<int> temp;
    backtrack(result, temp, nums, 0);
    return result;
  }
};

int main()
{
  Solution solution;
  vector<int> nums;
  int n, num;

  cin >> n; // Number of elements
  for (int i = 0; i < n; ++i)
  {
    cin >> num;
    nums.push_back(num);
  }

  vector<vector<int>> result = solution.subsetsWithDup(nums);

  for (const auto &subset : result)
  {
    cout << "[";
    for (size_t i = 0; i < subset.size(); ++i)
    {
      if (i > 0)
        cout << ",";
      cout << subset[i];
    }
    cout << "]" << endl;
  }

  return 0;
}

/*
Time Complexity: O(2^n) where n is the number of elements in nums, as there are 2^n possible subsets.
Space Complexity: O(2^n * n) for storing the result and the recursion stack.
*/
