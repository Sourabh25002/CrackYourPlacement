#include <bits/stdc++.h>
using namespace std;

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
  int rangeSumBST(TreeNode *root, int low, int high)
  {
    if (!root)
      return 0;
    if (root->val < low)
      return rangeSumBST(root->right, low, high);
    if (root->val > high)
      return rangeSumBST(root->left, low, high);
    return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
  }
};

int main()
{
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(5);
  root->right = new TreeNode(15);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(7);
  root->right->right = new TreeNode(18);

  Solution solution;
  int low = 7, high = 15;
  int result = solution.rangeSumBST(root, low, high);

  cout << "Sum of values in range [" << low << ", " << high << "] is: " << result << endl;

  return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)