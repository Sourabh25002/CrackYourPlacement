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
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    if (root == nullptr)
    {
      return nullptr;
    }

    if (root->val > p->val && root->val > q->val)
    {
      return lowestCommonAncestor(root->left, p, q);
    }
    else if (root->val < p->val && root->val < q->val)
    {
      return lowestCommonAncestor(root->right, p, q);
    }
    else
    {
      return root;
    }
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
  vector<int> nodes = {6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5};
  TreeNode *root = createTree(nodes);
  TreeNode *p = new TreeNode(2);
  TreeNode *q = new TreeNode(8);

  Solution sol;
  TreeNode *lca = sol.lowestCommonAncestor(root, p, q);
  if (lca)
  {
    cout << "Lowest Common Ancestor: " << lca->val << endl; // Expected Output: 6
  }

  return 0;
}

/*
Time Complexity: O(N), where N is the number of nodes in the tree, as each node is visited once in the worst case.
Space Complexity: O(N), for the recursive call stack in the worst case (completely unbalanced tree).
*/
