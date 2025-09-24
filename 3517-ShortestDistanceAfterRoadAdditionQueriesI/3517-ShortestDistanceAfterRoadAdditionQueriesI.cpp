// Last updated: 9/24/2025, 2:15:18 AM
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        map<int,int> umap;
        unordered_map<int,vector<int>> adjList;

        for(int i=0;i<n;i++) {
            umap[i]=n-i-1;
            if(i<n-1) adjList[i].push_back(i+1);
        }

        for(auto i:adjList){
            cout<<i.first<<"-";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }

        for(auto i:queries){
            

            int a = i[0];
            int b = i[1];
            adjList[a].push_back(b);
            for(int j=a;j>=0;j--){
                int ans=1e9;
                for(auto k:adjList[j]){
                    ans=min(ans,umap[k]);
                }
                umap[j]=1+ans;
            }
            
            ans.push_back(umap[0]);
            


        }

        return ans;
    }
};