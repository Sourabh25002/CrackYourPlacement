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

class Solution
{
public:
  vector<TreeNode *> generateTrees(int n)
  {
    if (n == 0)
      return {};
    return generate(1, n);
  }

  vector<TreeNode *> generate(int start, int end)
  {
    vector<TreeNode *> result;
    if (start > end)
    {
      result.push_back(NULL);
      return result;
    }

    for (int i = start; i <= end; ++i)
    {
      vector<TreeNode *> leftTrees = generate(start, i - 1);
      vector<TreeNode *> rightTrees = generate(i + 1, end);

      for (TreeNode *left : leftTrees)
      {
        for (TreeNode *right : rightTrees)
        {
          TreeNode *root = new TreeNode(i);
          root->left = left;
          root->right = right;
          result.push_back(root);
        }
      }
    }
    return result;
  }
};

// Helper function to print tree in pre-order
void printPreOrder(TreeNode *node)
{
  if (node == NULL)
  {
    cout << "null ";
    return;
  }
  cout << node->val << " ";
  printPreOrder(node->left);
  printPreOrder(node->right);
}

int main()
{
  Solution solution;
  int n = 3;
  vector<TreeNode *> trees = solution.generateTrees(n);

  for (TreeNode *tree : trees)
  {
    printPreOrder(tree);
    cout << endl;
  }

  return 0;
}

/*
Time Complexity: O(4^n / n^(3/2)) for generating all unique BSTs.
Space Complexity: O(4^n / n^(3/2)) for storing all unique BSTs.
*/
