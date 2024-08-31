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
  int getCountOfNode(TreeNode *root, int l, int h)
  {
    if (!root)
      return 0;
    if (root->val < l)
    {
      return getCountOfNode(root->right, l, h);
    }
    if (root->val > h)
    {
      return getCountOfNode(root->left, l, h);
    }
    return 1 + getCountOfNode(root->left, l, h) + getCountOfNode(root->right, l, h);
  }
};

int main()
{
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(5);
  root->right = new TreeNode(50);
  root->left->left = new TreeNode(1);
  root->right->left = new TreeNode(40);
  root->right->right = new TreeNode(100);

  Solution sol;
  int l = 5, h = 45;
  int result = sol.getCountOfNode(root, l, h);

  cout << "Number of nodes in the range [" << l << ", " << h << "] is: " << result << endl;

  // Cleanup the tree nodes
  delete root->right->left;
  delete root->right->right;
  delete root->left->left;
  delete root->left;
  delete root->right;
  delete root;

  return 0;
}

/*
Time Complexity: O(N), where N is the number of nodes in the BST, as each node is visited once.
Space Complexity: O(H), where H is the height of the BST, for the recursion stack.
*/
