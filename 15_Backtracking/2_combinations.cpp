#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void backtrack(vector<vector<int>> &result, vector<int> &temp, int start, int n, int k)
  {
    if (temp.size() == k)
    {
      result.push_back(temp);
      return;
    }

    for (int i = start; i <= n; ++i)
    {
      temp.push_back(i);
      backtrack(result, temp, i + 1, n, k);
      temp.pop_back(); // Remove the last element for the next iteration
    }
  }

  vector<vector<int>> combine(int n, int k)
  {
    vector<vector<int>> result;
    vector<int> temp;
    backtrack(result, temp, 1, n, k);
    return result;
  }
};

int main()
{
  Solution solution;
  int n, k;

  cin >> n >> k;

  vector<vector<int>> result = solution.combine(n, k);

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
Time Complexity: O(C(n, k) * k) where C(n, k) is the number of combinations and k is the length of each combination.
Space Complexity: O(C(n, k) * k) for storing the result and the recursion stack.
*/
