#include <bits/stdc++.h>
using namespace std;

// Function to compute the maximum area of a histogram
int maxHistogramArea(const vector<int> &heights)
{
  stack<int> s;
  int maxArea = 0;
  int tp;
  int areaWithTop;
  int i = 0;

  while (i < heights.size())
  {
    if (s.empty() || heights[i] >= heights[s.top()])
    {
      s.push(i++);
    }
    else
    {
      tp = s.top();
      s.pop();
      areaWithTop = heights[tp] * (s.empty() ? i : i - s.top() - 1);
      maxArea = max(maxArea, areaWithTop);
    }
  }

  while (!s.empty())
  {
    tp = s.top();
    s.pop();
    areaWithTop = heights[tp] * (s.empty() ? i : i - s.top() - 1);
    maxArea = max(maxArea, areaWithTop);
  }

  return maxArea;
}

// Function to find the maximum rectangle area with all 1s in the binary matrix
int maxRectangleArea(const vector<vector<int>> &matrix)
{
  if (matrix.empty())
    return 0;

  int rows = matrix.size();
  int cols = matrix[0].size();
  vector<int> heights(cols, 0);
  int maxArea = 0;

  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      heights[j] = (matrix[i][j] == 0) ? 0 : heights[j] + 1;
    }
    maxArea = max(maxArea, maxHistogramArea(heights));
  }

  return maxArea;
}

int main()
{
  int rows, cols;
  cout << "Input number of rows: ";
  cin >> rows;
  cout << "Input number of columns: ";
  cin >> cols;

  vector<vector<int>> matrix(rows, vector<int>(cols));

  cout << "Input matrix elements:" << endl;
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      cin >> matrix[i][j];
    }
  }

  cout << "Output: " << maxRectangleArea(matrix) << endl;

  return 0;
}

/*
Time Complexity: O(rows * cols), where rows is the number of rows and cols is the number of columns in the matrix.
Space Complexity: O(cols), where cols is the number of columns in the matrix (for the heights array).
*/
