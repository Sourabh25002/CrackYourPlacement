#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maximalRectangle(vector<vector<char>> &matrix)
  {
    if (matrix.empty() || matrix[0].empty())
      return 0;
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> height(cols, 0); // To store height of histogram bars
    int maxArea = 0;

    for (int i = 0; i < rows; ++i)
    {
      // Update the height array for the current row
      for (int j = 0; j < cols; ++j)
      {
        height[j] = (matrix[i][j] == '1') ? height[j] + 1 : 0;
      }
      maxArea = max(maxArea, largestRectangleArea(height));
    }

    return maxArea;
  }

private:
  int largestRectangleArea(vector<int> &heights)
  {
    stack<int> st;
    int maxArea = 0, area;
    heights.push_back(0); // Add a sentinel to handle remaining bars in the stack

    for (int i = 0; i < heights.size(); ++i)
    {
      while (!st.empty() && heights[i] < heights[st.top()])
      {
        int height = heights[st.top()];
        st.pop();
        int width = st.empty() ? i : i - st.top() - 1;
        area = height * width;
        maxArea = max(maxArea, area);
      }
      st.push(i);
    }

    return maxArea;
  }
};

int main()
{
  Solution sol;

  vector<vector<char>> matrix1 = {
      {'1', '0', '1', '0', '0'},
      {'1', '0', '1', '1', '1'},
      {'1', '1', '1', '1', '1'},
      {'1', '0', '0', '1', '0'}};
  cout << "Maximal Rectangle Area (Example 1): " << sol.maximalRectangle(matrix1) << endl; // Output: 6

  vector<vector<char>> matrix2 = {{'0'}};
  cout << "Maximal Rectangle Area (Example 2): " << sol.maximalRectangle(matrix2) << endl; // Output: 0

  vector<vector<char>> matrix3 = {{'1'}};
  cout << "Maximal Rectangle Area (Example 3): " << sol.maximalRectangle(matrix3) << endl; // Output: 1

  return 0;
}

/*
Time Complexity: O(rows * cols), where rows and cols are the dimensions of the matrix. Each cell is processed once in the height array and once in the largestRectangleArea function.
Space Complexity: O(cols), due to the height array and stack used in the largestRectangleArea function.
*/
