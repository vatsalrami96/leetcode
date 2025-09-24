// Last updated: 9/24/2025, 2:16:40 AM
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        set<int>hs;
        for(auto i:descriptions){
            hs.insert(i[1]);
        }
        int root=0;
        for(auto i:descriptions){
            if(hs.find(i[0]) == hs.end()){
                root = i[0];
                break;
            }
        }

        unordered_map<int,pair<int,int>> m;
        for(auto i:descriptions){
            if(i[2]==0) m[i[0]].second = i[1];
            else m[i[0]].first = i[1];
        }

        TreeNode* head = buildTree(root,m);
        return head;




    }

    TreeNode* buildTree(int root , unordered_map<int,pair<int,int>> &m){
        if(root==0) return nullptr;
        TreeNode* node = new TreeNode(root);
        node->left=buildTree(m[root].first,m);
        node->right=buildTree(m[root].second,m);
        return node;
    }



};
