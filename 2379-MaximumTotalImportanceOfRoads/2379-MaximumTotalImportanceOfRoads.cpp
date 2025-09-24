// Last updated: 9/24/2025, 2:16:34 AM
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans=0;
        vector<int> indegree(n,0);
        for(auto i:roads){
            indegree[i[0]]++;
            indegree[i[1]]++;
        }
        sort(indegree.begin(),indegree.end());
        for(long long i=0;i<n;i++){
            ans+= (i+1)*(indegree[i]);
        }

        return ans;
    }
};

