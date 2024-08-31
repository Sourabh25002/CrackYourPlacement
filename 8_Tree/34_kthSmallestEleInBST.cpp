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
  int solve(TreeNode *root, int &i, int k)
  {
    if (root == nullptr)
    {
      return -1;
    }

    int left = solve(root->left, i, k);
    if (left != -1)
    {
      return left;
    }

    i++;
    if (i == k)
    {
      return root->val;
    }

    return solve(root->right, i, k);
  }

  int kthSmallest(TreeNode *root, int k)
  {
    int i = 0;
    return solve(root, i, k);
  }
};

int main()
{
  // Constructing the example tree: [5,3,6,2,4,null,null,1]
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->left->left->left = new TreeNode(1);

  Solution sol;
  int k = 3;
  cout << "The " << k << "rd smallest element is: " << sol.kthSmallest(root, k) << endl;

  // Cleanup the tree nodes
  delete root->left->left->left;
  delete root->left->left;
  delete root->left->right;
  delete root->left;
  delete root->right;
  delete root;

  return 0;
}

/*
Time Complexity: O(n), where n is the number of nodes in the tree, due to the need to potentially visit all nodes.
Space Complexity: O(h), where h is the height of the tree, due to recursion stack space.
*/
