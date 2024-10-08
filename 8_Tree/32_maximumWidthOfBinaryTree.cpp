#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        int ans = 0;
        queue<pair<TreeNode*, long long>> q; // Using long long for indices
        q.push({root, 0});
        
        while (!q.empty()) {
            int size = q.size();
            long long curMin = q.front().second; // Using long long
            long long leftMost, rightMost; // Using long long
            
            for (int i = 0; i < size; i++) {
                long long cur_id = q.front().second - curMin; // Subtract to prevent integer overflow
                TreeNode* temp = q.front().first;
                q.pop();
                
                if (i == 0) leftMost = cur_id;
                if (i == size - 1) rightMost = cur_id;
                
                if (temp->left)
                    q.push({temp->left, cur_id * 2 + 1});
                if (temp->right)
                    q.push({temp->right, cur_id * 2 + 2});
            }
            ans = max(ans, static_cast<int>(rightMost - leftMost + 1)); // Convert to int for ans
        }
        
        return ans;
    }
};

int main() {
    // Constructing the example tree: [1,3,2,5,3,null,9]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    
    Solution solution;
    cout << "Maximum Width: " << solution.widthOfBinaryTree(root) << endl;
    
    // Cleanup the tree nodes
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

/*
Time Complexity: O(n), where n is the number of nodes in the tree, as each node is processed once.
Space Complexity: O(n), where n is the number of nodes in the tree, due to the space used by the queue.
*/
