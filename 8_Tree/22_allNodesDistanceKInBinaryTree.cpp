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
  void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_track, TreeNode *target)
  {
    queue<TreeNode *> queue;
    queue.push(root);

    while (!queue.empty())
    {
      TreeNode *current = queue.front();
      queue.pop();

      if (current->left)
      {
        parent_track[current->left] = current;
        queue.push(current->left);
      }
      if (current->right)
      {
        parent_track[current->right] = current;
        queue.push(current->right);
      }
    }
  }

  vector<int> allNodes(TreeNode *root, TreeNode *target, int k)
  {
    unordered_map<TreeNode *, TreeNode *> parent_track;
    markParents(root, parent_track, target);

    unordered_map<TreeNode *, bool> visited;
    queue<TreeNode *> queue;

    queue.push(target);
    visited[target] = true;

    int curr_level = 0;

    while (!queue.empty())
    {
      int size = queue.size();
      if (curr_level++ == k)
      {
        break;
      }

      for (int i = 0; i < size; i++)
      {
        TreeNode *current = queue.front();
        queue.pop();

        if (current->left && !visited[current->left])
        {
          queue.push(current->left);
          visited[current->left] = true;
        }
        if (current->right && !visited[current->right])
        {
          queue.push(current->right);
          visited[current->right] = true;
        }
        if (parent_track[current] && !visited[parent_track[current]])
        {
          queue.push(parent_track[current]);
          visited[parent_track[current]] = true;
        }
      }
    }

    vector<int> result;
    while (!queue.empty())
    {
      TreeNode *current = queue.front();
      queue.pop();
      result.push_back(current->val);
    }

    return result;
  }

  vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
  {
    return allNodes(root, target, k);
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
  root->left = newNode(5);
  root->right = newNode(1);
  root->left->left = newNode(6);
  root->left->right = newNode(2);
  root->right->left = newNode(0);
  root->right->right = newNode(8);
  root->left->right->left = newNode(7);
  root->left->right->right = newNode(4);

  Solution solution;
  TreeNode *target = root->left; // target is node with value 5
  int k = 2;

  vector<int> result = solution.distanceK(root, target, k);

  // Output the result
  for (int val : result)
  {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}

/*
Time Complexity: O(N) where N is the number of nodes in the binary tree.
Space Complexity: O(N) due to the space required for the parent map, visited map, and the queue.
*/
