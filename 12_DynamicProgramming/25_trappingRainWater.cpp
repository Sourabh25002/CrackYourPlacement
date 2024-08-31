#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &height)
{
  int n = height.size();
  if (n == 0)
    return 0;

  vector<int> leftMax(n), rightMax(n);
  leftMax[0] = height[0];
  rightMax[n - 1] = height[n - 1];

  for (int i = 1; i < n; ++i)
  {
    leftMax[i] = max(leftMax[i - 1], height[i]);
  }

  for (int i = n - 2; i >= 0; --i)
  {
    rightMax[i] = max(rightMax[i + 1], height[i]);
  }

  int waterTrapped = 0;
  for (int i = 0; i < n; ++i)
  {
    waterTrapped += min(leftMax[i], rightMax[i]) - height[i];
  }

  return waterTrapped;
}

int main()
{
  vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << "Trapped water for height1: " << trap(height1) << endl; // Output: 6

  vector<int> height2 = {4, 2, 0, 3, 2, 5};
  cout << "Trapped water for height2: " << trap(height2) << endl; // Output: 9

  return 0;
}

/*
Time Complexity: O(n), where n is the number of elements in the height array.
Space Complexity: O(n), due to the space required for leftMax and rightMax arrays.
*/
