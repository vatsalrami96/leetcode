// Last updated: 9/24/2025, 2:15:48 AM
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char, int> umap;
        for(char c : source + target) {
            if(umap.find(c) == umap.end()) umap[c] = umap.size();
        }
        for(char c : original) {
            if(umap.find(c) == umap.end()) umap[c] = umap.size();
        }
        for(char c : changed) {
            if(umap.find(c) == umap.end()) umap[c] = umap.size();
        }
        
        int n = umap.size();
        vector<vector<int>> d(n, vector<int>(n, -1));
        
        for(int i = 0; i < n; i++) {
            d[i][i] = 0;
        }
        
        for(int i = 0; i < original.size(); i++) {
            int a = umap[original[i]];
            int b = umap[changed[i]];
            if(d[a][b] == -1 || cost[i] < d[a][b]) {
                d[a][b] = cost[i];
            }
        }

        for(int via = 0; via < n; via++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(d[i][via] != -1 && d[via][j] != -1) {
                        if(d[i][j] == -1 || d[i][j] > d[i][via] + d[via][j]) {
                            d[i][j] = d[i][via] + d[via][j];
                        }
                    }
                }
            }
        }
        
        long long ans = 0;
        for(int i = 0; i < source.size(); i++) {
            if(source[i] != target[i]) {
                int a = umap[source[i]];
                int b = umap[target[i]];
                if(d[a][b] == -1) return -1;
                ans += d[a][b];
            }
        }

        return ans;
    }
};