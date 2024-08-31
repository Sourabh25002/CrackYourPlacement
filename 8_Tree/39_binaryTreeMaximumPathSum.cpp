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
  int findMaxPathSum(TreeNode *root, int &maxi)
  {
    if (root == nullptr)
      return 0;

    int leftMaxPath = max(0, findMaxPathSum(root->left, maxi));
    int rightMaxPath = max(0, findMaxPathSum(root->right, maxi));
    int value = root->val;
    maxi = max(maxi, leftMaxPath + rightMaxPath + value);
    return max(leftMaxPath, rightMaxPath) + value;
  }

  int maxPathSum(TreeNode *root)
  {
    int maxi = INT_MIN;
    findMaxPathSum(root, maxi);
    return maxi;
  }
};

int main()
{
  TreeNode *root = new TreeNode(-10);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  Solution sol;
  cout << "Maximum path sum: " << sol.maxPathSum(root) << endl; // Output: 42

  // Cleanup
  function<void(TreeNode *)> cleanup = [&](TreeNode *node)
  {
    if (!node)
      return;
    cleanup(node->left);
    cleanup(node->right);
    delete node;
  };
  cleanup(root);

  return 0;
}

/*
Time Complexity: O(N), where N is the number of nodes in the tree.
Space Complexity: O(H), where H is the height of the tree due to recursion stack.
*/
