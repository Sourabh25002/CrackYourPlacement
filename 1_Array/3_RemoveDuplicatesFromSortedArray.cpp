#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr)
{
  if (arr.empty())
    return 0; // Handle the case of an empty vector

  int i = 0;
  for (int j = 1; j < arr.size(); j++)
  {
    if (arr[i] != arr[j])
    {
      i++;
      arr[i] = arr[j];
    }
  }
  return i + 1;
}

int main()
{
  vector<int> arr = {1, 1, 2, 2, 2, 3, 3};
  int k = removeDuplicates(arr);
  cout << "The array after removing duplicate elements is " << endl;

  for (int i = 0; i < k; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}

// Time Complexity = O(N)
// Space Complexity = O(1)