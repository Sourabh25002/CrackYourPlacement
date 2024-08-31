#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 16; // Maximum number of cities
int dp[1 << MAXN][MAXN];
vector<vector<int>> dist; // Distance matrix

int tsp(int mask, int pos, int n)
{
  // Base case: if all cities have been visited
  if (mask == (1 << n) - 1)
  {
    return dist[pos][0]; // Return to the starting city
  }

  // If already computed
  if (dp[mask][pos] != -1)
  {
    return dp[mask][pos];
  }

  int answer = INF;
  // Try to go to every city from the current position
  for (int city = 0; city < n; ++city)
  {
    if (!(mask & (1 << city)))
    { // If city is not visited
      int newAnswer = dist[pos][city] + tsp(mask | (1 << city), city, n);
      answer = min(answer, newAnswer);
    }
  }

  return dp[mask][pos] = answer;
}

int main()
{
  int n;
  cin >> n; // Number of cities

  dist.assign(n, vector<int>(n));
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      cin >> dist[i][j];
    }
  }

  memset(dp, -1, sizeof(dp)); // Initialize dp array with -1
  int result = tsp(1, 0, n);  // Start with city 0 and only city 0 visited
  cout << "Minimum cost of visiting all cities: " << result << endl;

  return 0;
}

/*
Time Complexity: O(n^2 * 2^n), where n is the number of cities. This is due to the recursion with 2^n states and each state requiring O(n) operations.
Space Complexity: O(n * 2^n), for storing the dp table with size (2^n) * n.
*/
