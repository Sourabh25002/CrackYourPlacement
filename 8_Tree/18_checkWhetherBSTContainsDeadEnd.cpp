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
  bool isDeadEndUtil(TreeNode *root, int min_val, int max_val)
  {
    if (!root)
      return false;

    // If this is a leaf node
    if (!root->left && !root->right)
    {
      // If there is no space for any other node
      if (min_val == root->val - 1 && max_val == root->val + 1)
        return true;
      else
        return false;
    }

    // Check the left and right subtree recursively
    return isDeadEndUtil(root->left, min_val, root->val - 1) ||
           isDeadEndUtil(root->right, root->val + 1, max_val);
  }

  bool isDeadEnd(TreeNode *root)
  {
    return isDeadEndUtil(root, 1, INT_MAX);
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
  TreeNode *root1 = newNode(8);
  root1->left = newNode(5);
  root1->right = newNode(9);
  root1->left->left = newNode(2);
  root1->left->right = newNode(7);
  root1->left->left->left = newNode(1);

  Solution sol;
  bool result1 = sol.isDeadEnd(root1);
  cout << (result1 ? "Yes" : "No") << endl; // Expected Output: Yes

  // Example 2
  TreeNode *root2 = newNode(8);
  root2->left = newNode(7);
  root2->right = newNode(10);
  root2->left->left = newNode(2);
  root2->right->left = newNode(9);
  root2->right->right = newNode(13);

  bool result2 = sol.isDeadEnd(root2);
  cout << (result2 ? "Yes" : "No") << endl; // Expected Output: Yes

  return 0;
}

/*
Time Complexity: O(N), where N is the number of nodes in the BST
Space Complexity: O(N), due to the recursive call stack in the worst case
*/
