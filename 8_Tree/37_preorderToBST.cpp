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

// Function to build BST from preorder traversal
TreeNode *buildBSTFromPreorder(vector<int> &preorder, int &index, int bound)
{
  if (index >= preorder.size() || preorder[index] > bound)
  {
    return nullptr;
  }
  TreeNode *root = new TreeNode(preorder[index++]);
  root->left = buildBSTFromPreorder(preorder, index, root->val);
  root->right = buildBSTFromPreorder(preorder, index, bound);
  return root;
}

// Function to perform postorder traversal
void postOrderTraversal(TreeNode *root, vector<int> &result)
{
  if (!root)
    return;
  postOrderTraversal(root->left, result);
  postOrderTraversal(root->right, result);
  result.push_back(root->val);
}

int main()
{
  int N = 5;
  vector<int> preorder = {40, 30, 35, 80, 100};

  int index = 0;
  TreeNode *root = buildBSTFromPreorder(preorder, index, INT_MAX);

  vector<int> postOrderResult;
  postOrderTraversal(root, postOrderResult);

  cout << "Postorder traversal: ";
  for (int val : postOrderResult)
  {
    cout << val << " ";
  }
  cout << endl;

  // Cleanup the tree nodes
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
Time Complexity: O(N), where N is the number of nodes, as each node is processed once.
Space Complexity: O(N), for storing the nodes and recursion stack.
*/
