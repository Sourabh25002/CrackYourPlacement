#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Function to find if there is a celebrity in the party or not.
  int celebrity(vector<vector<int>> &mat)
  {
    int n = mat.size();
    stack<int> st;

    // Step 1: Push all elements (indices) into the stack
    for (int i = 0; i < n; i++)
    {
      st.push(i);
    }

    // Step 2: Run the discard method to get a potential celebrity
    while (st.size() > 1)
    {
      int a = st.top();
      st.pop();
      int b = st.top();
      st.pop();

      if (mat[a][b])
      {
        // If a knows b, then a can't be a celebrity, but b might be
        st.push(b);
      }
      else
      {
        // If a doesn't know b, then b can't be a celebrity, but a might be
        st.push(a);
      }
    }

    // Step 3: Verify the candidate
    int candidate = st.top();
    for (int i = 0; i < n; i++)
    {
      // The candidate should not know anyone, and everyone should know the candidate
      if (i != candidate && (mat[candidate][i] || !mat[i][candidate]))
      {
        return -1;
      }
    }

    return candidate;
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<vector<int>> mat1 = {{0, 1, 0},
                              {0, 0, 0},
                              {0, 1, 0}};
  cout << "Celebrity Index: " << sol.celebrity(mat1) << endl; // Output: 1

  // Example 2
  vector<vector<int>> mat2 = {{0, 1},
                              {1, 0}};
  cout << "Celebrity Index: " << sol.celebrity(mat2) << endl; // Output: -1

  return 0;
}

/*
Time Complexity: O(n) for finding the celebrity and O(n) for verification, resulting in an overall time complexity of O(n).
Space Complexity: O(1) as it uses a stack and a few additional variables.
*/
