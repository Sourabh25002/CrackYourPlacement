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
public:
  // Function to perform an inorder traversal and collect values in a vector
  void inorderTraversal(TreeNode *root, vector<int> &values)
  {
    if (!root)
      return;
    inorderTraversal(root->left, values);
    values.push_back(root->val);
    inorderTraversal(root->right, values);
  }

  // Function to find the median from a vector of values
  double findMedian(vector<int> &values)
  {
    int n = values.size();
    if (n % 2 == 1)
    {
      return values[n / 2];
    }
    else
    {
      return (values[n / 2 - 1] + values[n / 2]) / 2.0;
    }
  }

  // Function to find the median of the BST
  double findMedian(TreeNode *root)
  {
    vector<int> values;
    inorderTraversal(root, values);
    return findMedian(values);
  }
};

int main()
{
  Solution solution;

  // Constructing the binary search tree
  TreeNode *root = new TreeNode(6);
  root->left = new TreeNode(3);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(9);

  // Find and print the median
  double median = solution.findMedian(root);
  cout << "Median of the BST: " << median << endl;

  return 0;
}

/*
Time Complexity:
- O(N) for inorder traversal, where N is the number of nodes in the BST.
- O(N) for storing values in a vector and finding the median.

Space Complexity:
- O(N) for storing values in a vector.
- O(H) for the recursive call stack, where H is the height of the tree.
*/
