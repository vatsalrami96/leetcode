// Last updated: 9/24/2025, 2:15:21 AM
class Solution {
public:

    void helper(int u,int v, set<int>&s){
        auto l = s.lower_bound(u);
        auto h = s.upper_bound(v);
        s.erase(l,h);
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int>s;
        vector<int> result;
        for(int i=0;i<n;i++){
            s.insert(i);
        }
        for(auto q:queries){
            int u=q[0];
            int v=q[1];
            helper(u+1,v-1,s);
            result.push_back(s.size()-1);

        }

        return result;
    }
};