#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
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

class Solution
{
public:
  enum State
  {
    NOT_MONITORED,
    MONITORED_NO_CAMERA,
    MONITORED_WITH_CAMERA
  };

  int minCameraCover(TreeNode *root)
  {
    int cameraCount = 0;
    if (dfs(root, cameraCount) == NOT_MONITORED)
    {
      cameraCount++;
    }
    return cameraCount;
  }

private:
  State dfs(TreeNode *node, int &cameraCount)
  {
    if (!node)
      return MONITORED_NO_CAMERA;

    State left = dfs(node->left, cameraCount);
    State right = dfs(node->right, cameraCount);

    if (left == NOT_MONITORED || right == NOT_MONITORED)
    {
      cameraCount++;
      return MONITORED_WITH_CAMERA;
    }

    if (left == MONITORED_WITH_CAMERA || right == MONITORED_WITH_CAMERA)
    {
      return MONITORED_NO_CAMERA;
    }

    return NOT_MONITORED;
  }
};

int main()
{
  // Example usage:
  Solution sol;

  // Constructing Example 1 tree: [0,0,null,0,0]
  TreeNode *root1 = new TreeNode(0);
  root1->left = new TreeNode(0);
  root1->left->left = new TreeNode(0);
  root1->left->right = new TreeNode(0);

  // Test Case 1
  cout << "Minimum cameras needed: " << sol.minCameraCover(root1) << endl; // Output: 1

  // Constructing Example 2 tree: [0,0,null,0,null,0,null,null,0]
  TreeNode *root2 = new TreeNode(0);
  root2->left = new TreeNode(0);
  root2->left->left = new TreeNode(0);
  root2->left->left->left = new TreeNode(0);
  root2->left->left->left->left = new TreeNode(0);

  // Test Case 2
  cout << "Minimum cameras needed: " << sol.minCameraCover(root2) << endl; // Output: 2

  return 0;
}

/*
Time Complexity: O(N), where N is the number of nodes. Each node is visited once.
Space Complexity: O(H), where H is the height of the tree, due to recursion stack space.
*/
