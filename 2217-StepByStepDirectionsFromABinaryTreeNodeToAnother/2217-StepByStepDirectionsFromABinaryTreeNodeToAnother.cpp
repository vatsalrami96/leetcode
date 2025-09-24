// Last updated: 9/24/2025, 2:16:53 AM
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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = getLCA(root,startValue,destValue);
        string sourcePath="";
        string destPath="";
        traverse(lca,startValue,sourcePath);
        traverse(lca,destValue,destPath);
        for(auto &i:sourcePath){
            i='U';
        }
        return sourcePath+destPath;
    }

    TreeNode* getLCA(TreeNode* node, int p, int q){
        if(node == nullptr || node->val ==p || node->val ==q){
            return node;
        }
        TreeNode* l= getLCA(node->left,p,q);
        TreeNode* r= getLCA(node->right,p,q);

        if(l==nullptr && r==nullptr) return nullptr;
        if(l==nullptr) return r;
        if(r==nullptr) return l;
        return node;

    }

    bool traverse(TreeNode* node, int value, string &s){
        if(node == nullptr) return false;
        if(node->val==value) return true;
        s.push_back('L');
        if(traverse(node->left,value,s)) return true;
        s.pop_back();
        s.push_back('R');
        if(traverse(node->right,value,s)) return true;
        s.pop_back();
        return false;

    }
    
};