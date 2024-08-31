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
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
  void traverse(TreeNode *root, int x, int y, map<int, map<int, multiset<int>>> &nodes)
  {
    if (root)
    {
      nodes[x][y].insert(root->val);              // Insert the node value in the appropriate position
      traverse(root->left, x - 1, y + 1, nodes);  // Traverse left child
      traverse(root->right, x + 1, y + 1, nodes); // Traverse right child
    }
  }

public:
  vector<vector<int>> verticalTraversal(TreeNode *root)
  {
    map<int, map<int, multiset<int>>> nodes;
    traverse(root, 0, 0, nodes); // Start traversal from root

    vector<vector<int>> ans;
    for (const auto &p : nodes)
    { // Iterate over vertical columns
      vector<int> col;
      for (const auto &q : p.second)
      {                                                          // Iterate over levels within each column
        col.insert(col.end(), q.second.begin(), q.second.end()); // Collect sorted values
      }
      ans.push_back(col);
    }
    return ans;
  }
};

int main()
{
  Solution sol;

  // Constructing Example 1 tree: [3,9,20,null,null,15,7]
  TreeNode *root1 = new TreeNode(3);
  root1->left = new TreeNode(9);
  root1->right = new TreeNode(20);
  root1->right->left = new TreeNode(15);
  root1->right->right = new TreeNode(7);

  // Test Case 1
  vector<vector<int>> result1 = sol.verticalTraversal(root1);
  cout << "Vertical Order Traversal 1: ";
  for (const auto &vec : result1)
  {
    cout << "[";
    for (const auto &val : vec)
    {
      cout << val << " ";
    }
    cout << "] ";
  }
  cout << endl;

  // Constructing Example 2 tree: [1,2,3,4,5,6,7]
  TreeNode *root2 = new TreeNode(1);
  root2->left = new TreeNode(2);
  root2->right = new TreeNode(3);
  root2->left->left = new TreeNode(4);
  root2->left->right = new TreeNode(5);
  root2->right->left = new TreeNode(6);
  root2->right->right = new TreeNode(7);

  // Test Case 2
  vector<vector<int>> result2 = sol.verticalTraversal(root2);
  cout << "Vertical Order Traversal 2: ";
  for (const auto &vec : result2)
  {
    cout << "[";
    for (const auto &val : vec)
    {
      cout << val << " ";
    }
    cout << "] ";
  }
  cout << endl;

  return 0;
}

/*
Time Complexity: O(N log N), where N is the number of nodes. Sorting nodes at each vertical level takes log N time.
Space Complexity: O(N), where N is the number of nodes. Storing nodes in maps and sets requires linear space.
*/
