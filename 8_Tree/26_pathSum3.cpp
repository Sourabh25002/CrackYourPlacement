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
  int pathSum(TreeNode *root, int targetSum)
  {
    unordered_map<long, int> prefixSumCount;
    prefixSumCount[0] = 1; // For the case when the path itself is equal to targetSum

    return dfs(root, targetSum, 0, prefixSumCount);
  }

private:
  int dfs(TreeNode *node, int targetSum, long currentSum, unordered_map<long, int> &prefixSumCount)
  {
    if (!node)
      return 0;

    currentSum += node->val;
    int numPaths = prefixSumCount[currentSum - targetSum];

    prefixSumCount[currentSum]++;
    numPaths += dfs(node->left, targetSum, currentSum, prefixSumCount);
    numPaths += dfs(node->right, targetSum, currentSum, prefixSumCount);
    prefixSumCount[currentSum]--;

    return numPaths;
  }
};

// Helper function to create a new node
TreeNode *newNode(int val)
{
  TreeNode *node = new TreeNode(val);
  node->left = NULL;
  node->right = NULL;
  return node;
}

int main()
{

  TreeNode *root = newNode(10);
  root->left = newNode(5);
  root->right = newNode(-3);
  root->left->left = newNode(3);
  root->left->right = newNode(2);
  root->right->right = newNode(11);
  root->left->left->left = newNode(3);
  root->left->left->right = newNode(-2);
  root->left->right->right = newNode(1);

  Solution solution;
  int result = solution.pathSum(root, 8);

  cout << "Number of paths with sum = 8: " << result << endl;

  return 0;
}

/*
Time Complexity: O(N) where N is the number of nodes in the binary tree.
Space Complexity: O(N) for the hash map storing the prefix sums.
*/
