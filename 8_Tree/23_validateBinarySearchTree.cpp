#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  bool isBST(TreeNode *root, long min, long max)
  {
    if (root == NULL)
    {
      return true;
    }

    if (root->val > min && root->val < max)
    {
      bool left = isBST(root->left, min, root->val);
      bool right = isBST(root->right, root->val, max);

      return left && right;
    }
    else
    {
      return false;
    }
  }

  bool isValidBST(TreeNode *root)
  {
    if (root == NULL)
    {
      return true;
    }
    return isBST(root, LONG_MIN, LONG_MAX);
  }
};

// Helper function to create a new node
TreeNode *newNode(int val)
{
  TreeNode *node = new TreeNode(val);
  node->left = NULL;
  node->right = NULL;
  return node;
}

int main()
{

  TreeNode *root = newNode(2);
  root->left = newNode(1);
  root->right = newNode(3);

  Solution solution;
  bool result = solution.isValidBST(root);

  // Output the result
  cout << (result ? "True" : "False") << endl;

  return 0;
}

/*
Time Complexity: O(N) where N is the number of nodes in the binary tree.
Space Complexity: O(H) where H is the height of the tree, due to the recursion stack.
*/
