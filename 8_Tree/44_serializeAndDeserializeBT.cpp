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
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec
{
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root)
  {
    if (!root)
      return "";

    stringstream s;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
      TreeNode *curNode = q.front();
      q.pop();
      if (curNode == NULL)
        s << "#,";
      else
        s << curNode->val << ',';
      if (curNode != NULL)
      {
        q.push(curNode->left);
        q.push(curNode->right);
      }
    }
    return s.str();
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data)
  {
    if (data.empty())
      return NULL;

    stringstream s(data);
    string str;
    getline(s, str, ',');
    TreeNode *root = new TreeNode(stoi(str));
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
      TreeNode *node = q.front();
      q.pop();

      getline(s, str, ',');
      if (str == "#")
      {
        node->left = NULL;
      }
      else
      {
        TreeNode *leftNode = new TreeNode(stoi(str));
        node->left = leftNode;
        q.push(leftNode);
      }

      getline(s, str, ',');
      if (str == "#")
      {
        node->right = NULL;
      }
      else
      {
        TreeNode *rightNode = new TreeNode(stoi(str));
        node->right = rightNode;
        q.push(rightNode);
      }
    }
    return root;
  }
};

int main()
{
  Codec codec;

  // Constructing the binary tree [1,2,3,null,null,4,5]
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(5);

  // Serialize the binary tree
  string serialized = codec.serialize(root);
  cout << "Serialized: " << serialized << endl;

  // Deserialize the binary tree
  TreeNode *deserialized = codec.deserialize(serialized);
  string deserializedSerialized = codec.serialize(deserialized);
  cout << "Deserialized and re-serialized: " << deserializedSerialized << endl;

  return 0;
}

/*
Time Complexity:
- Serialize: O(N), where N is the number of nodes in the tree. Each node is processed once.
- Deserialize: O(N), where N is the number of nodes in the tree. Each node is processed once.

Space Complexity:
- Serialize: O(N) for storing the serialized string.
- Deserialize: O(N) for the queue and the binary tree nodes.
*/
