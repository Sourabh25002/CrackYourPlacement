#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height)
{
  int left = 0;
  int right = height.size() - 1;
  int maxi = 0;

  while (left < right)
  {
    int minHeight = min(height[left], height[right]);
    int width = right - left;
    int currentArea = minHeight * width;
    maxi = max(maxi, currentArea);

    if (height[left] < height[right])
    {
      left++;
    }
    else
    {
      right--;
    }
  }

  return maxi;
}

int main()
{

  vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  cout << "Maximum area: " << maxArea(height) << endl;

  return 0;
}

// Time Complexity = O(N)
// Space Complexity = O(1)