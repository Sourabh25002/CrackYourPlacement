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
  int sumOfLeftLeaves(TreeNode *root)
  {
    if (!root)
      return 0;

    int sum = 0;
    if (root->left)
    {
      if (!root->left->left && !root->left->right)
      {
        sum += root->left->val;
      }
      else
      {
        sum += sumOfLeftLeaves(root->left);
      }
    }
    sum += sumOfLeftLeaves(root->right);
    return sum;
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
  vector<int> nodes = {3, 9, 20, -1, -1, 15, 7};
  TreeNode *root = createTree(nodes);

  Solution sol;
  int result = sol.sumOfLeftLeaves(root);
  cout << "Sum of Left Leaves: " << result << endl; // Expected Output: 24

  return 0;
}

/*
Time Complexity: O(N), where N is the number of nodes in the tree. Each node is visited once.
Space Complexity: O(H), where H is the height of the tree. This is for the call stack during the recursive traversal.
*/
