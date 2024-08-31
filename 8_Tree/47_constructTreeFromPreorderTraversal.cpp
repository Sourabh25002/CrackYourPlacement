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
  TreeNode *constructTreeUtil(int &index, const vector<int> &pre, const vector<char> &preLN, int N)
  {
    // Base case
    if (index >= N)
      return nullptr;

    TreeNode *root = new TreeNode(pre[index]);

    // If the current node is a leaf node
    if (preLN[index] == 'L')
    {
      root->left = nullptr;
      root->right = nullptr;
    }
    else
    {
      // Move to the left and right children
      index++;
      root->left = constructTreeUtil(index, pre, preLN, N);
      index++;
      root->right = constructTreeUtil(index, pre, preLN, N);
    }

    return root;
  }

  TreeNode *constructTree(int N, const vector<int> &pre, const vector<char> &preLN)
  {
    int index = 0;
    return constructTreeUtil(index, pre, preLN, N);
  }
};

void inorderTraversal(TreeNode *root)
{
  if (!root)
    return;
  inorderTraversal(root->left);
  cout << root->val << " ";
  inorderTraversal(root->right);
}

int main()
{
  Solution solution;

  // Input
  int N = 5;
  vector<int> pre = {10, 30, 20, 5, 15};
  vector<char> preLN = {'N', 'N', 'L', 'L', 'L'};

  // Construct the binary tree
  TreeNode *root = solution.constructTree(N, pre, preLN);

  // Output the inorder traversal of the constructed binary tree
  cout << "Inorder traversal of the constructed binary tree: ";
  inorderTraversal(root);
  cout << endl;

  return 0;
}

/*
Time Complexity:
- O(N) where N is the number of nodes in the binary tree, as each node is processed once.

Space Complexity:
- O(N) for the recursion stack and tree node storage.
*/
