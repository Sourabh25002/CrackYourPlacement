#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
private:
  TreeNode *first = nullptr;
  TreeNode *second = nullptr;
  TreeNode *prev = new TreeNode(INT_MIN);

  void inorder(TreeNode *root)
  {
    if (!root)
      return;

    inorder(root->left);

    if (root->val < prev->val)
    {
      if (!first)
      {
        first = prev;
      }
      second = root;
    }
    prev = root;

    inorder(root->right);
  }

public:
  void recoverTree(TreeNode *root)
  {
    inorder(root);
    swap(first->val, second->val);
  }
};

int main()
{
  // Example usage:
  // Constructing the example tree: [3,1,4,null,null,2]
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(1);
  root->right = new TreeNode(4);
  root->right->left = new TreeNode(2);

  Solution solution;
  solution.recoverTree(root);

  // Output the recovered tree in level order to check correctness
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty())
  {
    TreeNode *node = q.front();
    q.pop();
    if (node)
    {
      cout << node->val << " ";
      q.push(node->left);
      q.push(node->right);
    }
    else
    {
      cout << "null ";
    }
  }
  cout << endl;

  return 0;
}

/*
Time Complexity: O(n), where n is the number of nodes in the tree, due to the in-order traversal.
Space Complexity: O(h), where h is the height of the tree, due to the recursion stack.
*/
