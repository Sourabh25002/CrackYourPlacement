#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void backtrack(vector<vector<int>> &result, vector<int> &temp, vector<int> &candidates, int target, int start)
  {
    if (target == 0)
    {
      result.push_back(temp);
      return;
    }

    for (int i = start; i < candidates.size(); ++i)
    {
      // Skip duplicates
      if (i > start && candidates[i] == candidates[i - 1])
        continue;
      if (candidates[i] > target)
        break; // No need to continue if the number is greater than the target

      temp.push_back(candidates[i]);
      backtrack(result, temp, candidates, target - candidates[i], i + 1);
      temp.pop_back(); // Remove the last element for the next iteration
    }
  }

  vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
  {
    vector<vector<int>> result;
    vector<int> temp;
    sort(candidates.begin(), candidates.end()); // Sort to handle duplicates and improve efficiency
    backtrack(result, temp, candidates, target, 0);
    return result;
  }
};

int main()
{
  Solution solution;
  vector<int> candidates;
  int target, n;

  cin >> n;
  candidates.resize(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> candidates[i];
  }
  cin >> target;

  vector<vector<int>> result = solution.combinationSum2(candidates, target);

  for (const auto &combination : result)
  {
    cout << "[";
    for (size_t i = 0; i < combination.size(); ++i)
    {
      if (i > 0)
        cout << ",";
      cout << combination[i];
    }
    cout << "]" << endl;
  }

  return 0;
}

/*
Time Complexity: O(2^n) in the worst case where n is the number of candidates, due to the recursion depth and combination generation.
Space Complexity: O(n) for the recursion stack and temporary storage.
*/
