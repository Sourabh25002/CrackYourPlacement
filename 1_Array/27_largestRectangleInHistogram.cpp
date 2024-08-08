#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int largestRectangleArea(vector<int> &heights)
  {
    int n = heights.size();

    // Step 1: Calculate the next smaller index for each bar
    vector<int> NSI(n);
    stack<int> st1;

    NSI[n - 1] = n; // Sentinel value for the last element
    st1.push(n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
      while (!st1.empty() && heights[st1.top()] >= heights[i])
      {
        st1.pop();
      }
      NSI[i] = st1.empty() ? n : st1.top();
      st1.push(i);
    }

    // Step 2: Calculate the previous smaller index for each bar
    vector<int> PSI(n);
    stack<int> st2;

    PSI[0] = -1; // Sentinel value for the first element
    st2.push(0);
    for (int i = 1; i < n; i++)
    {
      while (!st2.empty() && heights[st2.top()] >= heights[i])
      {
        st2.pop();
      }
      PSI[i] = st2.empty() ? -1 : st2.top();
      st2.push(i);
    }

    // Step 3: Calculate the maximum area
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
      int breadth = NSI[i] - PSI[i] - 1;
      int area = heights[i] * breadth;
      maxArea = max(maxArea, area);
    }

    return maxArea;
  }
};

int main()
{
  Solution sol;
  vector<int> heights1 = {2, 1, 5, 6, 2, 3};
  vector<int> heights2 = {2, 4};

  cout << "Largest Rectangle Area for heights1: " << sol.largestRectangleArea(heights1) << endl; // Output: 10
  cout << "Largest Rectangle Area for heights2: " << sol.largestRectangleArea(heights2) << endl; // Output: 4

  return 0;
}

/*
Time Complexity:
- Calculating NSI (Next Smaller Index) and PSI (Previous Smaller Index) both take O(n) time.
- Calculating the maximum area also takes O(n) time.
- Overall time complexity is O(n).

Space Complexity:
- We use two vectors (NSI and PSI) each of size n, and two stacks each of size n.
- Therefore, the space complexity is O(n).
*/
