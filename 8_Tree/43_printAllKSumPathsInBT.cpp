#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Function to print all k-sum paths starting from the given node
void printKSumPaths(TreeNode *root, int k, vector<int> &path)
{
  if (!root)
    return;

  // Add the current node to the path
  path.push_back(root->val);

  // Check for k-sum paths in the current path
  int sum = 0;
  for (int i = path.size() - 1; i >= 0; i--)
  {
    sum += path[i];
    if (sum == k)
    {
      for (int j = i; j < path.size(); j++)
        cout << path[j] << " ";
      cout << endl;
    }
  }

  // Recur for left and right subtrees
  printKSumPaths(root->left, k, path);
  printKSumPaths(root->right, k, path);

  // Remove the current node from the path to backtrack
  path.pop_back();
}

int main()
{
  // Constructing the binary tree
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(3);
  root->right = new TreeNode(-1);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(1);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(5);
  root->left->right->left = new TreeNode(1);
  root->right->left->left = new TreeNode(1);
  root->right->left->right = new TreeNode(2);
  root->right->right->right = new TreeNode(6);

  int k = 5;
  vector<int> path;

  cout << "K-Sum Paths:" << endl;
  printKSumPaths(root, k, path);

  return 0;
}

/*
Time Complexity: O(N^2), where N is the number of nodes in the tree. This is due to checking all paths for each node.
Space Complexity: O(N), where N is the number of nodes in the tree. This space is used for storing the path in the recursion stack.
*/
