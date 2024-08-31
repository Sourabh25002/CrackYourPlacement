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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root)
  {
    vector<vector<int>> result;
    dfs(root, 0, result);
    for (int i = 1; i < result.size(); i += 2)
    {
      reverse(result[i].begin(), result[i].end());
    }
    return result;
  }

private:
  void dfs(TreeNode *root, int level, vector<vector<int>> &result)
  {
    if (!root)
      return;
    if (level >= result.size())
    {
      result.push_back(vector<int>());
    }
    result[level].push_back(root->val);
    dfs(root->left, level + 1, result);
    dfs(root->right, level + 1, result);
  }
};

int main()
{
  // Constructing the example tree: [3,9,20,null,null,15,7]
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  Solution sol;
  vector<vector<int>> result = sol.zigzagLevelOrder(root);

  cout << "Zigzag Level Order Traversal:" << endl;
  for (const auto &level : result)
  {
    for (int val : level)
    {
      cout << val << " ";
    }
    cout << endl;
  }

  // Cleanup the tree nodes
  delete root->right->left;
  delete root->right->right;
  delete root->right;
  delete root->left;
  delete root;

  return 0;
}

/*
Time Complexity: O(n), where n is the number of nodes in the tree, as each node is visited once.
Space Complexity: O(n), where n is the number of nodes in the tree, for storing the result and recursion stack.
*/
