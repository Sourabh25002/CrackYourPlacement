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
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
private:
  struct BSTInfo
  {
    int size;   // Size of the BST
    int min;    // Minimum value in the BST
    int max;    // Maximum value in the BST
    bool isBST; // Whether the subtree is a BST
  };

  BSTInfo largestBSTSubtree(TreeNode *root)
  {
    if (!root)
    {
      return {0, INT_MAX, INT_MIN, true};
    }

    BSTInfo left = largestBSTSubtree(root->left);
    BSTInfo right = largestBSTSubtree(root->right);

    BSTInfo current;
    current.size = 0;
    current.isBST = false;

    if (left.isBST && right.isBST && root->val > left.max && root->val < right.min)
    {
      current.size = left.size + right.size + 1;
      current.min = min(root->val, left.min);
      current.max = max(root->val, right.max);
      current.isBST = true;
    }
    else
    {
      current.size = max(left.size, right.size);
      current.min = INT_MIN;
      current.max = INT_MAX;
      current.isBST = false;
    }

    return current;
  }

public:
  int largestBSTSubtree(TreeNode *root)
  {
    return largestBSTSubtree(root).size;
  }
};

int main()
{
  Solution solution;

  // Constructing the binary tree
  TreeNode *root = new TreeNode(6);
  root->left = new TreeNode(6);
  root->right = new TreeNode(2);
  root->left->right = new TreeNode(2);
  root->right->left = new TreeNode(1);
  root->right->right = new TreeNode(3);

  // Find and print the size of the largest BST subtree
  int largestBSTSize = solution.largestBSTSubtree(root);
  cout << "Size of the largest BST subtree: " << largestBSTSize << endl;

  return 0;
}

/*
Time Complexity:
- O(N) where N is the number of nodes in the binary tree, as each node is processed once.

Space Complexity:
- O(H) for the recursion stack, where H is the height of the binary tree.
*/
