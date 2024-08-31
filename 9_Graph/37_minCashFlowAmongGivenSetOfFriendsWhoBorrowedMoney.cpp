#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum creditor and debtor
pair<int, int> getMaxMin(vector<int> &netAmount)
{
  int n = netAmount.size();
  int maxCreditor = 0, maxDebtor = 0;
  for (int i = 1; i < n; i++)
  {
    if (netAmount[i] > netAmount[maxCreditor])
    {
      maxCreditor = i;
    }
    if (netAmount[i] < netAmount[maxDebtor])
    {
      maxDebtor = i;
    }
  }
  return {maxCreditor, maxDebtor};
}

// Function to minimize cash flow among friends
void minimizeCashFlow(vector<vector<int>> &transactions)
{
  int n = transactions.size();
  vector<int> netAmount(n, 0);

  // Calculate net amount for each person
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      netAmount[i] += transactions[j][i] - transactions[i][j];
    }
  }

  // Main function to settle the transactions
  while (true)
  {
    // Find the maximum creditor and debtor
    auto [creditor, debtor] = getMaxMin(netAmount);
    if (netAmount[creditor] <= 0 && netAmount[debtor] >= 0)
    {
      break;
    }

    // Find the minimum amount to settle
    int amount = min(-netAmount[debtor], netAmount[creditor]);

    // Update net amounts
    netAmount[creditor] -= amount;
    netAmount[debtor] += amount;

    cout << "Person " << debtor << " pays " << amount << " to Person " << creditor << endl;
  }
}

int main()
{
  // Example graph with 4 friends
  // transactions[i][j] means person i owes person j
  vector<vector<int>> transactions = {
      {0, 0, 0, 0},
      {0, 0, 0, 10},
      {0, 0, 0, 0},
      {0, 10, 0, 0}};

  minimizeCashFlow(transactions);

  return 0;
}

/*
Time Complexity: O(n^2), where n is the number of friends. This is due to calculating net amounts and finding maximum creditor and debtor.
Space Complexity: O(n), where n is the number of friends. This is due to storing net amounts for each friend.
*/
