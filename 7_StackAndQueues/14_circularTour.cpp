#include <bits/stdc++.h>
using namespace std;

struct petrolPump
{
  int petrol;
  int distance;
};

class Solution
{
public:
  // Function to find starting point where the truck can start to get through
  // the complete circle without exhausting its petrol in between.
  int tour(petrolPump p[], int n)
  {
    int shortage = 0; // Track the petrol shortage
    int start = 0;    // Starting index
    int balance = 0;  // Current balance of petrol

    for (int i = 0; i < n; i++)
    {
      balance += p[i].petrol - p[i].distance;

      // If balance is negative, we can't reach the next petrol pump
      if (balance < 0)
      {
        shortage += balance; // Add the deficit to the shortage
        start = i + 1;       // Start from the next petrol pump
        balance = 0;         // Reset the balance
      }
    }

    // If the total balance and shortage together are non-negative, return start index
    if (balance + shortage >= 0)
    {
      return start;
    }
    else
    {
      return -1;
    }
  }
};

int main()
{
  Solution sol;

  // Example 1
  int N = 4;
  petrolPump arr[] = {{4, 6}, {6, 5}, {7, 3}, {4, 5}};

  int result = sol.tour(arr, N);
  cout << "Starting point: " << result << endl; // Expected Output: 1

  return 0;
}

/*
Time Complexity: O(N) where N is the number of petrol pumps. We traverse the array once.

Space Complexity: O(1) since we use only a few extra variables for calculation.
*/
