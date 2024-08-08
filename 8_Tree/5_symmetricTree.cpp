#include <bits/stdc++.h>
using namespace std;

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
  bool isMirror(TreeNode *root1, TreeNode *root2)
  {
    if (root1 == NULL && root2 == NULL)
      return true;

    if (root1 && root2 && root1->val == root2->val)
      return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);

    return false;
  }

  bool isSymmetric(TreeNode *root)
  {
    return isMirror(root, root);
  }
};

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(3);

  Solution solution;
  bool result = solution.isSymmetric(root);

  cout << (result ? "Tree is symmetric" : "Tree is not symmetric") << endl;

  return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)