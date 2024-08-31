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

// Function to convert binary tree to DLL
void treeToDLL(TreeNode *root, TreeNode *&head, TreeNode *&tail)
{
  if (!root)
    return;

  // Process left subtree
  treeToDLL(root->left, head, tail);

  // If tail is null, we're at the leftmost node, which is the head of DLL
  if (!tail)
  {
    head = root;
  }
  else
  {
    // Link the current node with the previous node (tail)
    tail->right = root;
    root->left = tail;
  }
  tail = root; // Update the tail to be the current node

  // Process right subtree
  treeToDLL(root->right, head, tail);
}

// Function to print DLL in order
void printDLL(TreeNode *head)
{
  TreeNode *current = head;
  while (current)
  {
    cout << current->val << " ";
    current = current->right;
  }
  cout << endl;
}

// Function to print DLL in reverse order
void printReverseDLL(TreeNode *tail)
{
  TreeNode *current = tail;
  while (current)
  {
    cout << current->val << " ";
    current = current->left;
  }
  cout << endl;
}

int main()
{
  // Example tree
  //       10
  //      /   \
    //     20   30
  //   /   \
    //  40   60

  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(20);
  root->right = new TreeNode(30);
  root->left->left = new TreeNode(40);
  root->left->right = new TreeNode(60);

  TreeNode *head = nullptr;
  TreeNode *tail = nullptr;

  treeToDLL(root, head, tail);

  cout << "DLL in order: ";
  printDLL(head);

  cout << "DLL in reverse order: ";
  printReverseDLL(tail);

  // Cleanup the tree and DLL nodes
  function<void(TreeNode *)> cleanup = [&](TreeNode *node)
  {
    while (node)
    {
      TreeNode *next = node->right;
      delete node;
      node = next;
    }
  };
  cleanup(head);

  return 0;
}

/*
Time Complexity: O(N), where N is the number of nodes, as each node is visited once.
Space Complexity: O(H), where H is the height of the tree due to recursion stack.
*/
