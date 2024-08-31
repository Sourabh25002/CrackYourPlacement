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
  bool isSameTree(TreeNode *p, TreeNode *q)
  {
    if (p == nullptr && q == nullptr)
    {
      return true;
    }
    if (p != nullptr && q != nullptr)
    {
      return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    return false;
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
  vector<int> nodes_p = {1, 2, 3};
  vector<int> nodes_q = {1, 2, 3};

  TreeNode *p = createTree(nodes_p);
  TreeNode *q = createTree(nodes_q);

  Solution sol;
  bool result = sol.isSameTree(p, q);
  cout << (result ? "true" : "false") << endl; // Expected Output: true

  return 0;
}

/*
Time Complexity: O(N), where N is the number of nodes in the trees, as each node is visited once.
Space Complexity: O(N), for the recursive call stack in the worst case (completely unbalanced tree).
*/
