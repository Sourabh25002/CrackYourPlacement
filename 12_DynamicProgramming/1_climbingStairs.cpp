#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int climbStairs(int n)
  {
    if (n == 1)
      return 1;
    if (n == 2)
      return 2;

    int a = 1, b = 2;
    for (int i = 3; i <= n; ++i)
    {
      int c = a + b;
      a = b;
      b = c;
    }
    return b;
  }
};

int main()
{
  Solution sol;
  int n1 = 2;
  int n2 = 3;
  int n3 = 5;

  cout << "Ways to climb " << n1 << " stairs: " << sol.climbStairs(n1) << endl; // Output: 2
  cout << "Ways to climb " << n2 << " stairs: " << sol.climbStairs(n2) << endl; // Output: 3
  cout << "Ways to climb " << n3 << " stairs: " << sol.climbStairs(n3) << endl; // Output: 8

  return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
