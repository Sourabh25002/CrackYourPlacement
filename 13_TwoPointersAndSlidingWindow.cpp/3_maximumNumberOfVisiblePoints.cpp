#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int visiblePoints(vector<vector<int>> &points, int angle, vector<int> &location)
  {
    vector<double> angles;
    int extra = 0;

    for (auto &p : points)
    {
      if (p == location)
      {
        extra++;
      }
      else
      {
        double ang = atan2(p[1] - location[1], p[0] - location[0]) * 180 / M_PI;
        angles.push_back(ang);
      }
    }

    sort(angles.begin(), angles.end());

    int n = angles.size();
    for (int i = 0; i < n; i++)
    {
      angles.push_back(angles[i] + 360);
    }

    int max_visible = 0;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
      while (j < angles.size() && angles[j] - angles[i] <= angle)
      {
        j++;
      }
      max_visible = max(max_visible, j - i);
    }

    return max_visible + extra;
  }
};

int main()
{
  Solution sol;

  vector<vector<int>> points1 = {{2, 1}, {2, 2}, {3, 3}};
  int angle1 = 90;
  vector<int> location1 = {1, 1};
  cout << "Example 1 Output: " << sol.visiblePoints(points1, angle1, location1) << endl; // Output: 3

  vector<vector<int>> points2 = {{2, 1}, {2, 2}, {3, 4}, {1, 1}};
  int angle2 = 90;
  vector<int> location2 = {1, 1};
  cout << "Example 2 Output: " << sol.visiblePoints(points2, angle2, location2) << endl; // Output: 4

  vector<vector<int>> points3 = {{1, 0}, {2, 1}};
  int angle3 = 13;
  vector<int> location3 = {1, 1};
  cout << "Example 3 Output: " << sol.visiblePoints(points3, angle3, location3) << endl; // Output: 1

  return 0;
}

/*
Time Complexity: O(n log n), where n is the number of points. Sorting the angles takes O(n log n) time.
Space Complexity: O(n), used for storing the angles.
*/
