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
  TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
  {
    unordered_map<int, int> postorderIndex;
    for (int i = 0; i < postorder.size(); ++i)
    {
      postorderIndex[postorder[i]] = i;
    }
    return build(preorder, postorder, 0, preorder.size() - 1, 0, postorder.size() - 1, postorderIndex);
  }

private:
  TreeNode *build(const vector<int> &preorder, const vector<int> &postorder,
                  int preStart, int preEnd, int postStart, int postEnd,
                  unordered_map<int, int> &postorderIndex)
  {
    if (preStart > preEnd || postStart > postEnd)
      return nullptr;

    TreeNode *root = new TreeNode(preorder[preStart]);

    if (preStart == preEnd)
      return root;

    int leftRootValue = preorder[preStart + 1];
    int leftRootIndex = postorderIndex[leftRootValue];
    int leftSize = leftRootIndex - postStart + 1;

    root->left = build(preorder, postorder, preStart + 1, preStart + leftSize, postStart, leftRootIndex, postorderIndex);
    root->right = build(preorder, postorder, preStart + leftSize + 1, preEnd, leftRootIndex + 1, postEnd - 1, postorderIndex);

    return root;
  }
};

// Helper function to print the tree in level order for verification
void printTree(TreeNode *root)
{
  if (!root)
    return;
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty())
  {
    TreeNode *node = q.front();
    q.pop();
    cout << node->val << " ";
    if (node->left)
      q.push(node->left);
    if (node->right)
      q.push(node->right);
  }
  cout << endl;
}

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
  // Example usage
  vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
  vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};

  Solution solution;
  TreeNode *root = solution.constructFromPrePost(preorder, postorder);

  cout << "Constructed Binary Tree (Level Order): ";
  printTree(root);

  return 0;
}

/*
Time Complexity: O(N) where N is the number of nodes in the tree.
Space Complexity: O(N) for the hash map and recursion stack.
*/
