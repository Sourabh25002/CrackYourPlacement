#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
  Node *connect(Node *root)
  {
    if (!root)
      return nullptr;

    Node *level_start = root;

    while (level_start->left)
    {
      Node *current = level_start;
      while (current)
      {
        current->left->next = current->right;
        if (current->next)
        {
          current->right->next = current->next->left;
        }
        current = current->next;
      }
      level_start = level_start->left;
    }
    return root;
  }
};

int main()
{
  // Example usage:
  // Constructing the example tree: [1,2,3,4,5,6,7]
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  Solution solution;
  solution.connect(root);

  // Output the tree levels using next pointers
  Node *level = root;
  while (level)
  {
    Node *current = level;
    while (current)
    {
      cout << current->val << "->";
      current = current->next;
    }
    cout << "NULL" << endl;
    level = level->left;
  }

  return 0;
}

/*
Time Complexity: O(n), where n is the number of nodes in the tree, as each node is visited exactly once.
Space Complexity: O(1), as no extra space is used other than a few pointers.
*/
