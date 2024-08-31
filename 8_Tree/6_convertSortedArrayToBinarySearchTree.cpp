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
  TreeNode *sortedArrayToBST(vector<int> &nums)
  {
    return helper(nums, 0, nums.size() - 1);
  }

  TreeNode *helper(vector<int> &nums, int left, int right)
  {
    if (left > right)
      return nullptr;

    int mid = left + (right - left) / 2;
    TreeNode *node = new TreeNode(nums[mid]);
    node->left = helper(nums, left, mid - 1);
    node->right = helper(nums, mid + 1, right);
    return node;
  }
};

// Utility function to print the tree in pre-order traversal
void preOrder(TreeNode *node)
{
  if (node == nullptr)
    return;
  cout << node->val << " ";
  preOrder(node->left);
  preOrder(node->right);
}

int main()
{
  vector<int> nums1 = {-10, -3, 0, 5, 9};
  Solution sol;
  TreeNode *result1 = sol.sortedArrayToBST(nums1);
  preOrder(result1); // Expected Output: 0 -10 -3 5 9
  cout << endl;

  vector<int> nums2 = {1, 3};
  TreeNode *result2 = sol.sortedArrayToBST(nums2);
  preOrder(result2); // Expected Output: 3 1
  cout << endl;

  return 0;
}

/*
Time Complexity: O(N), where N is the number of elements in the array, as we are visiting each element exactly once.
Space Complexity: O(logN), which is the height of the tree for the recursion stack.
*/
