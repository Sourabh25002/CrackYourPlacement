#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> waterJugBFS(int x, int y, int z)
{
  vector<pair<int, int>> result;
  unordered_set<string> visited;
  queue<pair<int, int>> q;

  // Initial state
  q.push({0, 0});
  visited.insert("0,0");
  result.push_back({0, 0});

  while (!q.empty())
  {
    auto [a, b] = q.front();
    q.pop();

    // Check if we have achieved the desired amount
    if (a == z || b == z)
    {
      break;
    }

    // All possible states from (a, b)
    vector<pair<int, int>> nextStates = {
        {x, b}, {a, y}, // Fill either jug
        {0, b},
        {a, 0},                                 // Empty either jug
        {a - min(a, y - b), b + min(a, y - b)}, // Pour from jug1 to jug2
        {a + min(b, x - a), b - min(b, x - a)}  // Pour from jug2 to jug1
    };

    for (auto [nextA, nextB] : nextStates)
    {
      string state = to_string(nextA) + "," + to_string(nextB);
      if (visited.find(state) == visited.end())
      {
        visited.insert(state);
        result.push_back({nextA, nextB});
        q.push({nextA, nextB});
      }
    }
  }

  return result;
}

int main()
{
  // Example 1
  int x1 = 4, y1 = 3, z1 = 2;
  vector<pair<int, int>> result1 = waterJugBFS(x1, y1, z1);
  cout << "Path for (" << x1 << ", " << y1 << ", " << z1 << "): ";
  for (const auto &p : result1)
  {
    cout << "(" << p.first << ", " << p.second << ") ";
  }
  cout << endl;

  // Example 2
  int x2 = 3, y2 = 5, z2 = 4;
  vector<pair<int, int>> result2 = waterJugBFS(x2, y2, z2);
  cout << "Path for (" << x2 << ", " << y2 << ", " << z2 << "): ";
  for (const auto &p : result2)
  {
    cout << "(" << p.first << ", " << p.second << ") ";
  }
  cout << endl;

  return 0;
}

/*
Time Complexity: O(X * Y), where X is the capacity of jug1 and Y is the capacity of jug2. Each state is processed once.
Space Complexity: O(X * Y), for storing states in the visited set and queue.
*/
