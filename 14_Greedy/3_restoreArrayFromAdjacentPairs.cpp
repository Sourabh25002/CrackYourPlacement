#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
  {
    unordered_map<int, vector<int>> adj;
    vector<int> result;

    // Building adjacency list
    for (auto &pair : adjacentPairs)
    {
      adj[pair[0]].push_back(pair[1]);
      adj[pair[1]].push_back(pair[0]);
    }

    // Find the starting element (element with only one neighbor)
    int start;
    for (auto &it : adj)
    {
      if (it.second.size() == 1)
      {
        start = it.first;
        break;
      }
    }

    // Reconstruct the array
    unordered_set<int> visited;
    int current = start;
    while (visited.size() < adj.size())
    {
      result.push_back(current);
      visited.insert(current);
      for (auto &neighbor : adj[current])
      {
        if (visited.find(neighbor) == visited.end())
        {
          current = neighbor;
          break;
        }
      }
    }

    return result;
  }
};

int main()
{
  Solution solution;

  vector<vector<int>> adjacentPairs1 = {{2, 1}, {3, 4}, {3, 2}};
  vector<int> result1 = solution.restoreArray(adjacentPairs1);
  cout << "Example 1 Output: ";
  for (int num : result1)
  {
    cout << num << " ";
  }
  cout << endl; // Output: [1,2,3,4] (or any valid solution)

  vector<vector<int>> adjacentPairs2 = {{4, -2}, {1, 4}, {-3, 1}};
  vector<int> result2 = solution.restoreArray(adjacentPairs2);
  cout << "Example 2 Output: ";
  for (int num : result2)
  {
    cout << num << " ";
  }
  cout << endl; // Output: [-2,4,1,-3] (or any valid solution)

  vector<vector<int>> adjacentPairs3 = {{100000, -100000}};
  vector<int> result3 = solution.restoreArray(adjacentPairs3);
  cout << "Example 3 Output: ";
  for (int num : result3)
  {
    cout << num << " ";
  }
  cout << endl; // Output: [100000,-100000] (or any valid solution)

  return 0;
}

/*
Time Complexity: O(n), where n is the number of elements in nums.
Space Complexity: O(n), for storing the adjacency list and the result array.
*/
