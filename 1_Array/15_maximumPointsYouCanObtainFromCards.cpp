#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxScore(vector<int> &cardPoints, int k)
  {
    int size = cardPoints.size(); // Size of the cardPoints array
    int i = size - k;             // Start index of the sliding window
    int j = i;                    // End index of the sliding window
    int sum = 0;                  // Current sum of the window
    int ans = 0;                  // Maximum score obtained

    // Compute the initial sum of the first window of size k
    for (int m = 0; m < k; ++m)
    {
      sum += cardPoints[m];
    }
    ans = sum;

    // Slide the window across the array
    while (j < size + k - 1)
    {
      j++;
      sum += cardPoints[j % size]; // Add the new card
      sum -= cardPoints[i % size]; // Remove the old card
      i++;
      ans = max(ans, sum); // Update the maximum score
    }

    return ans;
  }
};

int main()
{
  Solution sol;

  // Example test cases
  vector<int> cardPoints1 = {1, 2, 3, 4, 5, 6, 1};
  int k1 = 3;
  cout << "Maximum score for cardPoints [1, 2, 3, 4, 5, 6, 1] with k = 3: " << sol.maxScore(cardPoints1, k1) << endl;

  vector<int> cardPoints2 = {2, 2, 2};
  int k2 = 2;
  cout << "Maximum score for cardPoints [2, 2, 2] with k = 2: " << sol.maxScore(cardPoints2, k2) << endl;

  vector<int> cardPoints3 = {9, 7, 7, 9, 7, 7, 9};
  int k3 = 7;
  cout << "Maximum score for cardPoints [9, 7, 7, 9, 7, 7, 9] with k = 7: " << sol.maxScore(cardPoints3, k3) << endl;

  return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)