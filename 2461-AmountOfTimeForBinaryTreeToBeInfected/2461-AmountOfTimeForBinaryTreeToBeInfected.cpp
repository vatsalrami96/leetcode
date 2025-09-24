// Last updated: 9/24/2025, 2:16:26 AM
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
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* temp = dfs(root,start);
        map<TreeNode*,TreeNode*> mp;
        unordered_set<TreeNode*> visited;
        traverse(root,mp);
        for(auto p:mp){
            cout <<p.first->val<<"-"<<p.second->val<<endl;
        }
        int time=-1;
        queue<TreeNode*> q;
        q.push(temp);
        while(!q.empty()){
            int n = q.size();
            while(n!=0){
                TreeNode* node = q.front();
                q.pop();                
                             
                if(node->left!=nullptr && visited.find(node->left)==visited.end()) q.push(node->left);
                if(node->right!=nullptr && visited.find(node->right)==visited.end()) q.push(node->right);
                if(node!=root && visited.find(mp[node])==visited.end())q.push(mp[node]);   
                visited.insert(node);
                n--;
            }
            time++;
        }
        return time;

    }
    TreeNode* dfs(TreeNode* node,int start){
        if(node==nullptr) return nullptr;
        if(node->val==start) return node;
        TreeNode* left = dfs(node->left,start);
        TreeNode* right =dfs(node->right,start);
        if(left!=nullptr) return left;
        if(right!=nullptr) return right;
        return left;
    }
    void traverse(TreeNode* node,map<TreeNode*,TreeNode*> &mp ){
        if(node==nullptr) return ;
        if(node->left!=nullptr) mp[node->left]=node;
        if(node->right!=nullptr) mp[node->right]=node;
        traverse(node->left,mp);
        traverse(node->right,mp);
    }
};