#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Helper function for Depth-First Search
  int dfs(int node, const vector<vector<int>> &adj, const vector<int> &informTime)
  {
    int maxTime = 0;
    for (int child : adj[node])
    {
      maxTime = max(maxTime, dfs(child, adj, informTime));
    }
    return maxTime + informTime[node];
  }

  int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
  {
    // Step 1: Build the adjacency list
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; ++i)
    {
      if (manager[i] != -1)
      {
        adj[manager[i]].push_back(i);
      }
    }

    // Step 2: Perform DFS from the head of the company
    return dfs(headID, adj, informTime);
  }
};

int main()
{
  Solution sol;

  int n1 = 1;
  int headID1 = 0;
  vector<int> manager1 = {-1};
  vector<int> informTime1 = {0};

  int n2 = 6;
  int headID2 = 2;
  vector<int> manager2 = {2, 2, -1, 2, 2, 2};
  vector<int> informTime2 = {0, 0, 1, 0, 0, 0};

  int result1 = sol.numOfMinutes(n1, headID1, manager1, informTime1);
  int result2 = sol.numOfMinutes(n2, headID2, manager2, informTime2);

  cout << "Time needed for example 1: " << result1 << " minutes" << endl;
  cout << "Time needed for example 2: " << result2 << " minutes" << endl;

  return 0;
}

/*
Time Complexity: O(n), where n is the number of employees.
Space Complexity: O(n), for the adjacency list and recursion stack.
*/
