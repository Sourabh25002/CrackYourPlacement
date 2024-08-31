#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator
{
private:
  stack<TreeNode *> stk;

  // Helper function to push all left children of a node to the stack
  void pushAllLeft(TreeNode *node)
  {
    while (node != NULL)
    {
      stk.push(node);
      node = node->left;
    }
  }

public:
  BSTIterator(TreeNode *root)
  {
    pushAllLeft(root);
  }

  int next()
  {
    TreeNode *node = stk.top();
    stk.pop();
    if (node->right != NULL)
    {
      pushAllLeft(node->right);
    }
    return node->val;
  }

  bool hasNext()
  {
    return !stk.empty();
  }
};

// Helper function to create a new node
TreeNode *newNode(int val)
{
  return new TreeNode(val);
}

int main()
{
  // Example tree construction: [7, 3, 15, null, null, 9, 20]
  TreeNode *root = newNode(7);
  root->left = newNode(3);
  root->right = newNode(15);
  root->right->left = newNode(9);
  root->right->right = newNode(20);

  BSTIterator bSTIterator = BSTIterator(root);

  cout << bSTIterator.next() << endl;                         // Output: 3
  cout << bSTIterator.next() << endl;                         // Output: 7
  cout << (bSTIterator.hasNext() ? "true" : "false") << endl; // Output: true
  cout << bSTIterator.next() << endl;                         // Output: 9
  cout << (bSTIterator.hasNext() ? "true" : "false") << endl; // Output: true
  cout << bSTIterator.next() << endl;                         // Output: 15
  cout << (bSTIterator.hasNext() ? "true" : "false") << endl; // Output: true
  cout << bSTIterator.next() << endl;                         // Output: 20
  cout << (bSTIterator.hasNext() ? "true" : "false") << endl; // Output: false

  return 0;
}

/*
Time Complexity:
- next(): O(1) on average for each call
- hasNext(): O(1)
Space Complexity: O(h) where h is the height of the BST, due to the stack
*/
