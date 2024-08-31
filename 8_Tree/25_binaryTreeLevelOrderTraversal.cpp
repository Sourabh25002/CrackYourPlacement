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
  vector<vector<int>> levelOrder(TreeNode *root)
  {
    vector<vector<int>> v;
    queue<TreeNode *> q;

    if (root == NULL)
    {
      return v;
    }
    q.push(root);
    while (!q.empty())
    {
      int n = q.size();
      vector<int> in;

      for (int i = 1; i <= n; i++)
      {
        TreeNode *temp = q.front();
        q.pop();
        in.push_back(temp->val);

        if (temp->left != NULL)
        {
          q.push(temp->left);
        }
        if (temp->right != NULL)
        {
          q.push(temp->right);
        }
      }
      v.push_back(in);
    }
    return v;
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

  TreeNode *root = newNode(3);
  root->left = newNode(9);
  root->right = newNode(20);
  root->right->left = newNode(15);
  root->right->right = newNode(7);

  Solution solution;
  vector<vector<int>> result = solution.levelOrder(root);

  // Output the result
  for (const auto &level : result)
  {
    for (int val : level)
    {
      cout << val << " ";
    }
    cout << endl;
  }

  return 0;
}

/*
Time Complexity: O(N) where N is the number of nodes in the binary tree.
Space Complexity: O(W) where W is the maximum width of the tree, which is the space used by the queue.
*/
