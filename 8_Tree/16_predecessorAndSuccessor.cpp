#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct Node
{
  int key;
  Node *left;
  Node *right;
  Node(int x) : key(x), left(NULL), right(NULL) {}
};

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
  if (root == NULL)
    return;

  if (root->key == key)
  {
    // Predecessor (max value in left subtree)
    if (root->left != NULL)
    {
      Node *tmp = root->left;
      while (tmp->right)
        tmp = tmp->right;
      pre = tmp;
    }

    // Successor (min value in right subtree)
    if (root->right != NULL)
    {
      Node *tmp = root->right;
      while (tmp->left)
        tmp = tmp->left;
      suc = tmp;
    }
    return;
  }

  if (root->key > key)
  {
    suc = root;
    findPreSuc(root->left, pre, suc, key);
  }
  else
  {
    pre = root;
    findPreSuc(root->right, pre, suc, key);
  }
}

Node *insert(Node *node, int key)
{
  if (node == NULL)
    return new Node(key);

  if (key < node->key)
    node->left = insert(node->left, key);
  else if (key > node->key)
    node->right = insert(node->right, key);

  return node;
}

int main()
{
  // Example 1
  Node *root1 = NULL;
  root1 = insert(root1, 8);
  insert(root1, 1);
  insert(root1, 9);
  insert(root1, 4);
  insert(root1, 10);
  insert(root1, 3);

  Node *pre = NULL;
  Node *suc = NULL;
  int key1 = 8;

  findPreSuc(root1, pre, suc, key1);
  cout << (pre ? to_string(pre->key) : "-1") << " "
       << (suc ? to_string(suc->key) : "-1") << endl; // Expected Output: 4 9

  // Example 2
  Node *root2 = NULL;
  root2 = insert(root2, 10);
  insert(root2, 2);
  insert(root2, 11);
  insert(root2, 1);
  insert(root2, 5);
  insert(root2, 3);
  insert(root2, 6);
  insert(root2, 4);

  pre = NULL;
  suc = NULL;
  int key2 = 11;

  findPreSuc(root2, pre, suc, key2);
  cout << (pre ? to_string(pre->key) : "-1") << " "
       << (suc ? to_string(suc->key) : "-1") << endl; // Expected Output: 10 -1

  return 0;
}

/*
Time Complexity: O(Height of the BST)
Space Complexity: O(Height of the BST) due to the recursion stack
*/
