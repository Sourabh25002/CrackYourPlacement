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
  void flatten(TreeNode *root)
  {
    TreeNode *curr = root;

    while (curr)
    {
      if (curr->left)
      {
        TreeNode *pre = curr->left;
        while (pre->right)
        {
          pre = pre->right;
        }
        pre->right = curr->right;

        curr->right = curr->left;
        curr->left = nullptr;
      }
      curr = curr->right;
    }
  }
};

int main()
{
  // Constructing the example tree: [1,2,5,3,4,null,6]
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(5);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(6);

  Solution solution;
  solution.flatten(root);

  // Output the flattened tree
  TreeNode *current = root;
  while (current)
  {
    cout << current->val << "->";
    current = current->right;
  }
  cout << "NULL" << endl;

  return 0;
}

/*
Time Complexity: O(n), where n is the number of nodes in the tree, as each node is visited once.
Space Complexity: O(1), as no extra space is used other than a few pointers.
*/
