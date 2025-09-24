// Last updated: 9/24/2025, 2:16:28 AM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isLeafNode(TreeNode* node){
        return node->left==nullptr && node->right==nullptr;
    }

    bool evaluateTree(TreeNode* root) {
        if(isLeafNode(root)) return root->val;
        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);
        return (root->val==2)? left || right: left && right;

    }
};