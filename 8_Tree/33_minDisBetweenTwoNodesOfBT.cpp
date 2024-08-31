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

// Helper function to find the lowest common ancestor (LCA) of nodes a and b
TreeNode *findLCA(TreeNode *root, int a, int b)
{
  if (!root)
    return nullptr;
  if (root->val == a || root->val == b)
    return root;

  TreeNode *left = findLCA(root->left, a, b);
  TreeNode *right = findLCA(root->right, a, b);

  if (left && right)
    return root;
  return left ? left : right;
}

// Helper function to find the distance from a given node to a target node
int findDistance(TreeNode *root, int target, int distance)
{
  if (!root)
    return -1;
  if (root->val == target)
    return distance;

  int leftDist = findDistance(root->left, target, distance + 1);
  int rightDist = findDistance(root->right, target, distance + 1);

  return max(leftDist, rightDist);
}

// Main function to find the minimum distance between nodes a and b
int findDist(TreeNode *root, int a, int b)
{
  TreeNode *lca = findLCA(root, a, b);
  int distanceA = findDistance(lca, a, 0);
  int distanceB = findDistance(lca, b, 0);
  return distanceA + distanceB;
}

int main()
{
  // Constructing the example tree: [11,22,33,44,55,66,77]
  TreeNode *root = new TreeNode(11);
  root->left = new TreeNode(22);
  root->right = new TreeNode(33);
  root->left->left = new TreeNode(44);
  root->left->right = new TreeNode(55);
  root->right->left = new TreeNode(66);
  root->right->right = new TreeNode(77);

  int a = 77, b = 22;
  cout << "Minimum Distance: " << findDist(root, a, b) << endl;

  // Cleanup the tree nodes
  delete root->left->left;
  delete root->left->right;
  delete root->right->left;
  delete root->right->right;
  delete root->left;
  delete root->right;
  delete root;

  return 0;
}

/*
Time Complexity: O(n), where n is the number of nodes in the tree. This is due to traversing the tree to find LCA and distances.
Space Complexity: O(h), where h is the height of the tree, due to recursion stack space.
*/
