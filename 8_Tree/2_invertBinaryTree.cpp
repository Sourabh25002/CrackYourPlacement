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
  void invert(TreeNode *root)
  {
    if (root == nullptr)
      return;

    TreeNode *leftRoot = root->left;
    TreeNode *rightRoot = root->right;

    root->left = rightRoot;
    root->right = leftRoot;

    invert(root->left);
    invert(root->right);
  }

  TreeNode *invertTree(TreeNode *root)
  {
    invert(root);
    return root;
  }
};

int main()
{
  // Creating a sample binary tree
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(7);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(9);

  // Inverting the binary tree
  Solution solution;
  root = solution.invertTree(root);

  // Function to print the tree in level order
  auto printTree = [](TreeNode *root)
  {
    if (root == nullptr)
      return;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
      TreeNode *node = q.front();
      q.pop();
      cout << node->val << " ";
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    }
    cout << endl;
  };

  // Printing the inverted binary tree
  printTree(root);

  return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
