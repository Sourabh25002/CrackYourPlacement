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
  TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
  {
    if (!root1)
      return root2;
    if (!root2)
      return root1;

    root1->val += root2->val;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);

    return root1;
  }
};

// Utility function to print the tree in level order
void printLevelOrder(TreeNode *root)
{
  if (!root)
    return;
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
}

int main()
{
  TreeNode *root1 = new TreeNode(1);
  root1->left = new TreeNode(3);
  root1->right = new TreeNode(2);
  root1->left->left = new TreeNode(5);

  TreeNode *root2 = new TreeNode(2);
  root2->left = new TreeNode(1);
  root2->right = new TreeNode(3);
  root2->left->right = new TreeNode(4);
  root2->right->right = new TreeNode(7);

  Solution sol;
  TreeNode *mergedTree = sol.mergeTrees(root1, root2);

  printLevelOrder(mergedTree); // Expected Output: 3 4 5 5 4 null 7

  return 0;
}

/*
Time Complexity: O(N), where N is the number of nodes in the smaller tree, as we are visiting each node exactly once.
Space Complexity: O(H), where H is the height of the tree, for the recursion stack.
*/
