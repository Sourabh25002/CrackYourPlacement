#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
  vector<int> inorderTraversal(TreeNode *root)
  {
    vector<int> r;
    if (root == NULL)
    {
      return r;
    }
    vector<int> x;
    if (root->left != NULL)
    {
      x = inorderTraversal(root->left);
      r.insert(r.end(), x.begin(), x.end());
    }
    r.push_back(root->val);
    if (root->right != NULL)
    {
      x = inorderTraversal(root->right);
      r.insert(r.end(), x.begin(), x.end());
    }
    return r;
  }
};

// Helper function to create a new node
TreeNode *newNode(int val)
{
  return new TreeNode(val);
}

int main()
{
  // Example 1
  TreeNode *root1 = newNode(1);
  root1->right = newNode(2);
  root1->right->left = newNode(3);

  Solution sol;
  vector<int> result1 = sol.inorderTraversal(root1);
  for (int v : result1)
    cout << v << " "; // Expected Output: 1 3 2
  cout << endl;

  // Example 2
  TreeNode *root2 = NULL;

  vector<int> result2 = sol.inorderTraversal(root2);
  for (int v : result2)
    cout << v << " "; // Expected Output: (empty)
  cout << endl;

  // Example 3
  TreeNode *root3 = newNode(1);

  vector<int> result3 = sol.inorderTraversal(root3);
  for (int v : result3)
    cout << v << " "; // Expected Output: 1
  cout << endl;

  return 0;
}

/*
Time Complexity: O(n) where n is the number of nodes in the binary tree
Space Complexity: O(n) for storing the output in the result vector and recursion stack space
*/
