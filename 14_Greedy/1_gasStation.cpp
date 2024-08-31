#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
  {
    int total_gas = 0, total_cost = 0, start = 0, tank = 0;

    for (int i = 0; i < gas.size(); i++)
    {
      total_gas += gas[i];
      total_cost += cost[i];
      tank += gas[i] - cost[i];

      if (tank < 0)
      {
        start = i + 1;
        tank = 0;
      }
    }

    return total_gas >= total_cost ? start : -1;
  }
};

int main()
{
  Solution sol;

  vector<int> gas1 = {1, 2, 3, 4, 5};
  vector<int> cost1 = {3, 4, 5, 1, 2};
  cout << "Example 1 Output: " << sol.canCompleteCircuit(gas1, cost1) << endl; // Output: 3

  vector<int> gas2 = {2, 3, 4};
  vector<int> cost2 = {3, 4, 3};
  cout << "Example 2 Output: " << sol.canCompleteCircuit(gas2, cost2) << endl; // Output: -1

  return 0;
}

/*
Time Complexity: O(n), where n is the length of the gas array.
Space Complexity: O(1), as we are using only a constant amount of extra space.
*/
