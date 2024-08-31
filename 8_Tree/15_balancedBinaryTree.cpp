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
  int dfsHeight(TreeNode *root)
  {
    if (root == NULL)
      return 0;

    int leftHeight = dfsHeight(root->left);
    if (leftHeight == -1)
      return -1;

    int rightHeight = dfsHeight(root->right);
    if (rightHeight == -1)
      return -1;

    if (abs(leftHeight - rightHeight) > 1)
      return -1;

    return max(leftHeight, rightHeight) + 1;
  }

  bool isBalanced(TreeNode *root)
  {
    return dfsHeight(root) != -1;
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
  vector<int> nodes1 = {3, 9, 20, -1, -1, 15, 7};
  TreeNode *root1 = createTree(nodes1);

  Solution sol;
  cout << "Is Balanced: " << (sol.isBalanced(root1) ? "True" : "False") << endl; // Expected Output: True

  vector<int> nodes2 = {1, 2, 2, 3, 3, -1, -1, 4, 4};
  TreeNode *root2 = createTree(nodes2);

  cout << "Is Balanced: " << (sol.isBalanced(root2) ? "True" : "False") << endl; // Expected Output: False

  vector<int> nodes3 = {};
  TreeNode *root3 = createTree(nodes3);

  cout << "Is Balanced: " << (sol.isBalanced(root3) ? "True" : "False") << endl; // Expected Output: True

  return 0;
}

/*
Time Complexity: O(N), where N is the number of nodes in the tree. Each node is visited once.
Space Complexity: O(H), where H is the height of the tree. This is for the call stack during the recursive traversal.
*/
