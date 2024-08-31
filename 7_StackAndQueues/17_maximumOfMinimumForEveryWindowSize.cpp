#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> maxOfMin(int arr[], int n)
  {
    vector<int> res(n, 0);
    vector<int> left(n, -1), right(n, n);

    // Calculate the previous smaller element for each element
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
      while (!s.empty() && arr[s.top()] >= arr[i])
      {
        s.pop();
      }
      left[i] = s.empty() ? -1 : s.top();
      s.push(i);
    }

    // Calculate the next smaller element for each element
    while (!s.empty())
    {
      s.pop();
    }
    for (int i = n - 1; i >= 0; i--)
    {
      while (!s.empty() && arr[s.top()] > arr[i])
      {
        s.pop();
      }
      right[i] = s.empty() ? n : s.top();
      s.push(i);
    }

    // Compute the maximum of the minimums for each window size
    for (int i = 0; i < n; i++)
    {
      int len = right[i] - left[i] - 1;
      res[len - 1] = max(res[len - 1], arr[i]);
    }

    // Fill in the maximum values for all window sizes
    for (int i = n - 2; i >= 0; i--)
    {
      res[i] = max(res[i], res[i + 1]);
    }

    return res;
  }
};

int main()
{
  Solution sol;

  // Example 1
  int arr1[] = {10, 20, 30, 50, 10, 70, 30};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  vector<int> result1 = sol.maxOfMin(arr1, n1);
  cout << "Example 1 Output: ";
  for (int num : result1)
  {
    cout << num << " ";
  }
  cout << endl; // Expected Output: 70 30 20 10 10 10 10

  // Example 2
  int arr2[] = {10, 20, 30};
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  vector<int> result2 = sol.maxOfMin(arr2, n2);
  cout << "Example 2 Output: ";
  for (int num : result2)
  {
    cout << num << " ";
  }
  cout << endl; // Expected Output: 30 20 10

  return 0;
}

/*
Time Complexity: O(N), where N is the number of elements in the array.
   - The first loop computes the previous smaller elements in O(N) time.
   - The second loop computes the next smaller elements in O(N) time.
   - Updating the result array also takes O(N) time.

Space Complexity: O(N), where N is the number of elements in the array.
   - Additional space is used for the `left`, `right`, and `res` arrays, each of size N.
*/
