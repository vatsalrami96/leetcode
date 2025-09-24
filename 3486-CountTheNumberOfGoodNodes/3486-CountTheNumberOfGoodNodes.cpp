// Last updated: 9/24/2025, 2:15:28 AM
class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        vector<int> childrens(n, 0);
        
        for(auto i : edges) {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        } 
        
        int c = 0;
        dfs(0, -1, adj, childrens, c);   
        return c;
    }

    void dfs(int node, int par, vector<vector<int>> &adj, vector<int> &childrens, int &c) {
        int total = 0;
        for(auto child : adj[node]) {
            if(child != par) {
                dfs(child, node, adj, childrens, c);
                total += childrens[child];
            }
        }
        childrens[node] = total + 1;
        
        int f = -1;
        for(auto child : adj[node]) {
            if(child != par) {
                if(f == -1) {
                    f = childrens[child];
                } else if(childrens[child] != f) {
                    return;
                }
            }
        }
        c++;
    }
};
