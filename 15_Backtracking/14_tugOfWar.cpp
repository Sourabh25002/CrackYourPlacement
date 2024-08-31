#include <bits/stdc++.h>
using namespace std;

class TugOfWar
{
public:
  vector<int> bestSubset1;
  vector<int> bestSubset2;
  int minDiff = INT_MAX;

  void findBestSubset(vector<int> &arr, vector<int> &current, vector<bool> &chosen, int index, int subsetSize, int size)
  {
    if (current.size() == subsetSize)
    {
      vector<int> remaining;
      for (int i = 0; i < size; ++i)
      {
        if (!chosen[i])
        {
          remaining.push_back(arr[i]);
        }
      }

      int sum1 = accumulate(current.begin(), current.end(), 0);
      int sum2 = accumulate(remaining.begin(), remaining.end(), 0);
      int diff = abs(sum1 - sum2);

      if (diff < minDiff)
      {
        minDiff = diff;
        bestSubset1 = current;
        bestSubset2 = remaining;
      }
      return;
    }

    if (index >= size)
      return;

    current.push_back(arr[index]);
    chosen[index] = true;
    findBestSubset(arr, current, chosen, index + 1, subsetSize, size);

    current.pop_back();
    chosen[index] = false;
    findBestSubset(arr, current, chosen, index + 1, subsetSize, size);
  }

  void solve(vector<int> &arr)
  {
    int size = arr.size();
    if (size <= 1)
      return;

    vector<int> current;
    vector<bool> chosen(size, false);
    int subsetSize = size / 2;
    if (size % 2 != 0)
      subsetSize = (size - 1) / 2;

    findBestSubset(arr, current, chosen, 0, subsetSize, size);

    cout << "Subset 1: ";
    for (int num : bestSubset1)
      cout << num << " ";
    cout << endl;

    cout << "Subset 2: ";
    for (int num : bestSubset2)
      cout << num << " ";
    cout << endl;
  }
};

int main()
{
  TugOfWar solution;

  vector<int> arr1 = {3, 4, 5, -3, 100, 1, 89, 54, 23, 20};
  solution.solve(arr1);

  vector<int> arr2 = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
  solution.solve(arr2);

  return 0;
}

/*
Time Complexity: O(2^N * N), where N is the number of elements in the array. The algorithm explores all possible subsets and calculates their sums.
Space Complexity: O(N), due to the usage of additional data structures for tracking subsets and chosen elements.
*/
