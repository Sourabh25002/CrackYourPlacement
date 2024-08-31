#include <bits/stdc++.h>
using namespace std;

// Function to check if it is possible to allocate books with the given maximum pages limit
bool isPossible(const vector<int> &arr, int n, int m, int maxPages)
{
  int studentCount = 1;
  int currentPages = 0;

  for (int i = 0; i < n; ++i)
  {
    if (arr[i] > maxPages)
    {
      return false; // Book pages exceed the maximum allowed pages
    }

    if (currentPages + arr[i] > maxPages)
    {
      ++studentCount;
      currentPages = arr[i];
      if (studentCount > m)
      {
        return false; // More students required than allowed
      }
    }
    else
    {
      currentPages += arr[i];
    }
  }

  return true;
}

// Function to find the minimum number of pages that can be allocated to the students
int allocateMinimumPages(const vector<int> &arr, int n, int m)
{
  if (m > n)
  {
    return -1; // More students than books
  }

  int sum = accumulate(arr.begin(), arr.end(), 0);
  int maxElement = *max_element(arr.begin(), arr.end());

  int left = maxElement;
  int right = sum;
  int result = right;

  while (left <= right)
  {
    int mid = left + (right - left) / 2;

    if (isPossible(arr, n, m, mid))
    {
      result = mid;
      right = mid - 1;
    }
    else
    {
      left = mid + 1;
    }
  }

  return result;
}

int main()
{
  vector<int> arr = {12, 34, 67, 90}; // Example input
  int n = arr.size();
  int m = 2;
  cout << "Minimum number of pages: " << allocateMinimumPages(arr, n, m) << endl;

  arr = {15, 17, 20}; // Another example input
  n = arr.size();
  m = 5;
  cout << "Minimum number of pages: " << allocateMinimumPages(arr, n, m) << endl;

  return 0;
}

/*
Time Complexity: O(n log sum), where n is the number of books and sum is the sum of pages in the books.
Space Complexity: O(1), as we are using only a few additional variables.
*/
