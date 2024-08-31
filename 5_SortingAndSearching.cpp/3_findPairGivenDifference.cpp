#include <bits/stdc++.h>
using namespace std;

int findPair(const vector<int> &arr, int x)
{
  int n = arr.size();

  // Use a set to store elements
  unordered_set<int> s;

  for (int num : arr)
  {
    // Check if the complement (num + x) or (num - x) exists in the set
    if (s.find(num + x) != s.end() || s.find(num - x) != s.end())
    {
      return 1;
    }
    // Insert the current number into the set
    s.insert(num);
  }

  return -1;
}

int main()
{
  vector<int> arr1 = {5, 20, 3, 2, 5, 80};
  int x1 = 78;
  cout << findPair(arr1, x1) << endl; // Output: 1

  vector<int> arr2 = {90, 70, 20, 80, 50};
  int x2 = 45;
  cout << findPair(arr2, x2) << endl; // Output: -1

  return 0;
}

/*
Time Complexity: O(n), where n is the number of elements in the array. Each element is processed once.
Space Complexity: O(n), due to the storage of elements in the unordered set.
*/
