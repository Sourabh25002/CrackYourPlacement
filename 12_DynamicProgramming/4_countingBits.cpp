#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> countBits(int n)
  {
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; ++i)
    {
      ans[i] = ans[i >> 1] + (i & 1);
    }
    return ans;
  }
};

int main()
{
  Solution sol;

  int n1 = 2;
  vector<int> result1 = sol.countBits(n1);
  cout << "Count bits for n1: ";
  for (int i : result1)
  {
    cout << i << " ";
  }
  cout << endl; // Output: [0, 1, 1]

  int n2 = 5;
  vector<int> result2 = sol.countBits(n2);
  cout << "Count bits for n2: ";
  for (int i : result2)
  {
    cout << i << " ";
  }
  cout << endl; // Output: [0, 1, 1, 2, 1, 2]

  return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
