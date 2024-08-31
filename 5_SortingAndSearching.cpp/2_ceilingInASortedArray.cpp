#include <bits/stdc++.h>
using namespace std;

// Function to find the ceiling of x in a sorted array
int findCeiling(const vector<int> &arr, int x)
{
  int n = arr.size();

  if (x <= arr[0])
  {
    return arr[0]; // x is smaller than or equal to the first element
  }

  for (int i = 0; i < n - 1; ++i)
  {
    if (arr[i] <= x && x <= arr[i + 1])
    {
      return arr[i + 1]; // x is between arr[i] and arr[i + 1]
    }
  }

  return -1; // No ceiling found (x is greater than the last element)
}

int main()
{
  vector<int> arr = {1, 2, 8, 10, 10, 12, 19};

  int x = 5;
  int ceiling = findCeiling(arr, x);
  if (ceiling != -1)
  {
    cout << "Ceiling of " << x << " is " << ceiling << endl;
  }
  else
  {
    cout << "Ceiling of " << x << " does not exist in the array" << endl;
  }

  return 0;
}

/*
Time Complexity: O(n), where n is the number of elements in the array. This is due to the linear search.
Space Complexity: O(1), as no additional space is used.
*/
