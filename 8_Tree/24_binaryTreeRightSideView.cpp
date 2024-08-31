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
  void recursion(TreeNode *root, int level, vector<int> &res)
  {
    if (root == NULL)
      return;
    if (res.size() == level)
      res.push_back(root->val);
    recursion(root->right, level + 1, res);
    recursion(root->left, level + 1, res);
  }

  vector<int> rightSideView(TreeNode *root)
  {
    vector<int> res;
    recursion(root, 0, res);
    return res;
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

  TreeNode *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->right = newNode(5);
  root->right->right = newNode(4);

  Solution solution;
  vector<int> result = solution.rightSideView(root);

  // Output the result
  for (int val : result)
  {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}

/*
Time Complexity: O(N) where N is the number of nodes in the binary tree.
Space Complexity: O(H) where H is the height of the tree, due to the recursion stack.
*/
