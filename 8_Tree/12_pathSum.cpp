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
  bool hasPathSum(TreeNode *root, int targetSum)
  {
    if (root == nullptr)
    {
      return false;
    }

    // If we've reached a leaf node, check if the sum equals targetSum
    if (root->left == nullptr && root->right == nullptr)
    {
      return targetSum == root->val;
    }

    // Recur down the tree and reduce the targetSum by the current node's value
    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
  }
};

// Utility function to create a tree from an array (level order)
TreeNode *createTree(const vector<int> &nodes)
{
  if (nodes.empty() || nodes[0] == -1)
    return nullptr;

  TreeNode *root = new TreeNode(nodes[0]);
  queue<TreeNode *> q;
  q.push(root);

  int i = 1;
  while (i < nodes.size())
  {
    TreeNode *current = q.front();
    q.pop();

    if (nodes[i] != -1)
    {
      current->left = new TreeNode(nodes[i]);
      q.push(current->left);
    }
    i++;
    if (i >= nodes.size())
      break;

    if (nodes[i] != -1)
    {
      current->right = new TreeNode(nodes[i]);
      q.push(current->right);
    }
    i++;
  }
  return root;
}

int main()
{
  vector<int> nodes = {5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, 1};
  int targetSum = 22;

  TreeNode *root = createTree(nodes);

  Solution sol;
  bool result = sol.hasPathSum(root, targetSum);
  cout << (result ? "true" : "false") << endl; // Expected Output: true

  return 0;
}

/*
Time Complexity: O(N), where N is the number of nodes in the tree. Each node is visited once.
Space Complexity: O(H), where H is the height of the tree. This is for the call stack in the recursion.
*/
