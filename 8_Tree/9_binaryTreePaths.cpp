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
  vector<string> binaryTreePaths(TreeNode *root)
  {
    vector<string> paths;
    if (!root)
      return paths;
    string path = to_string(root->val);
    if (!root->left && !root->right)
    {
      paths.push_back(path);
    }
    else
    {
      if (root->left)
      {
        dfs(root->left, path, paths);
      }
      if (root->right)
      {
        dfs(root->right, path, paths);
      }
    }
    return paths;
  }

private:
  void dfs(TreeNode *node, string path, vector<string> &paths)
  {
    path += "->" + to_string(node->val);
    if (!node->left && !node->right)
    {
      paths.push_back(path);
    }
    else
    {
      if (node->left)
      {
        dfs(node->left, path, paths);
      }
      if (node->right)
      {
        dfs(node->right, path, paths);
      }
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
  vector<int> nodes = {1, 2, 3, -1, 5};
  TreeNode *root = createTree(nodes);

  Solution sol;
  vector<string> result = sol.binaryTreePaths(root);
  cout << "Binary Tree Paths:" << endl;
  for (const string &path : result)
  {
    cout << path << endl; // Expected Output: ["1->2->5","1->3"]
  }

  return 0;
}

/*
Time Complexity: O(N), where N is the number of nodes in the tree, as each node is visited once.
Space Complexity: O(N), for storing the paths and the recursive call stack.
*/
