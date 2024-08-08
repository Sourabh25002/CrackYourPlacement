#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
  bool isIdentical(TreeNode *node1, TreeNode *node2)
  {
    if (node1 == nullptr && node2 == nullptr)
    {
      return true;
    }
    if (node1 == nullptr || node2 == nullptr)
    {
      return false;
    }
    return (node1->val == node2->val) &&
           isIdentical(node1->left, node2->left) &&
           isIdentical(node1->right, node2->right);
  }

  bool isSubtree(TreeNode *root, TreeNode *subRoot)
  {
    if (root == nullptr)
    {
      return false;
    }
    if (root->val == subRoot->val && isIdentical(root, subRoot))
    {
      return true;
    }
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }
};

int main()
{
  // Creating a sample binary tree root
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(4);
  root->right = new TreeNode(5);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(2);

  // Creating a sample binary tree subRoot
  TreeNode *subRoot = new TreeNode(4);
  subRoot->left = new TreeNode(1);
  subRoot->right = new TreeNode(2);

  Solution solution;
  bool result = solution.isSubtree(root, subRoot);

  cout << "Is subRoot a subtree of root? " << (result ? "Yes" : "No") << endl;

  return 0;
}

// Time Complexity: O(m * n)
// Space Complexity: O(1)