// Last updated: 9/24/2025, 2:16:37 AM
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
    int averageOfSubtree(TreeNode* root) {
        return __averageOfSubtree(root);    

    }
    int __averageOfSubtree(TreeNode* node){
        if(node==nullptr){
            return 0;
        }
        int noOfNodes=0;
        int totalSum = countSum(node,noOfNodes);
        if((totalSum/noOfNodes)==node->val){
            return 1 + __averageOfSubtree(node->left) + __averageOfSubtree(node->right);
        }
        return 0 + __averageOfSubtree(node->left) + __averageOfSubtree(node->right);

    }
    int countSum(TreeNode* node, int &totalNodes){
        if(node==nullptr){
            return 0;
        }
        totalNodes++;
        int lefty = countSum(node->left,totalNodes);
        int righty = countSum(node->right,totalNodes);
        return node->val+lefty+righty;
    }
    
};