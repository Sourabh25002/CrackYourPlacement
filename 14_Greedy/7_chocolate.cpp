#include <bits/stdc++.h>
using namespace std;

int minimalCost(vector<int> &verticalCosts, vector<int> &horizontalCosts, int m, int n)
{
  sort(verticalCosts.rbegin(), verticalCosts.rend());
  sort(horizontalCosts.rbegin(), horizontalCosts.rend());

  int verticalIndex = 0, horizontalIndex = 0;
  int verticalCuts = 1, horizontalCuts = 1;
  int totalCost = 0;

  while (verticalIndex < verticalCosts.size() && horizontalIndex < horizontalCosts.size())
  {
    if (verticalCuts < m)
    {
      totalCost += verticalCuts * verticalCosts[verticalIndex];
      verticalIndex++;
      verticalCuts++;
    }
    else
    {
      totalCost += horizontalCuts * horizontalCosts[horizontalIndex];
      horizontalIndex++;
      horizontalCuts++;
    }
  }

  while (verticalIndex < verticalCosts.size())
  {
    totalCost += verticalCuts * verticalCosts[verticalIndex];
    verticalIndex++;
  }

  while (horizontalIndex < horizontalCosts.size())
  {
    totalCost += horizontalCuts * horizontalCosts[horizontalIndex];
    horizontalIndex++;
  }

  return totalCost;
}

int main()
{
  int T;
  cin >> T;
  cin.ignore(); // ignore the blank line after the number of test cases

  while (T--)
  {
    if (T < 20)
      cin.ignore(); // ignore the blank line between test cases

    int m, n;
    cin >> m >> n;

    vector<int> verticalCosts(m - 1);
    vector<int> horizontalCosts(n - 1);

    for (int i = 0; i < m - 1; i++)
    {
      cin >> verticalCosts[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
      cin >> horizontalCosts[i];
    }

    cout << minimalCost(verticalCosts, horizontalCosts, m, n) << endl;
  }

  return 0;
}

/*
Time Complexity: O((m-1 + n-1) log(m-1 + n-1)), due to sorting the costs.
Space Complexity: O(m + n), to store the costs for vertical and horizontal breaks.
*/
