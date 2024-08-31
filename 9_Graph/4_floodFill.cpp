#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int newColor, int delRow[], int delCol[], int iniColor)
  {
    ans[row][col] = newColor;
    int n = image.size();
    int m = image[0].size();
    for (int i = 0; i < 4; i++)
    {
      int nrow = row + delRow[i];
      int ncol = col + delCol[i];
      if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor)
      {
        dfs(nrow, ncol, ans, image, newColor, delRow, delCol, iniColor);
      }
    }
  }

public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
  {
    int iniColor = image[sr][sc];
    vector<vector<int>> ans = image;
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    dfs(sr, sc, ans, image, newColor, delRow, delCol, iniColor);
    return ans;
  }
};

int main()
{
  Solution solution;

  // Example 1
  vector<vector<int>> image1 = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
  int sr1 = 1, sc1 = 1, color1 = 2;
  vector<vector<int>> result1 = solution.floodFill(image1, sr1, sc1, color1);
  for (auto row : result1)
  {
    for (auto pixel : row)
    {
      cout << pixel << " ";
    }
    cout << endl;
  }

  // Example 2
  vector<vector<int>> image2 = {{0, 0, 0}, {0, 0, 0}};
  int sr2 = 0, sc2 = 0, color2 = 0;
  vector<vector<int>> result2 = solution.floodFill(image2, sr2, sc2, color2);
  for (auto row : result2)
  {
    for (auto pixel : row)
    {
      cout << pixel << " ";
    }
    cout << endl;
  }

  return 0;
}

/*
Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/
