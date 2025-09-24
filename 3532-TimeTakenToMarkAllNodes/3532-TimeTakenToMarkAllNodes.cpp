// Last updated: 9/24/2025, 2:15:15 AM
class Solution {
public:
    vector<int>max1;
    vector<int>max2;
    vector<vector<int>>adjList;

    int dfs1(int node , int parent) {
        int currMax1 = 0;
        int currMax2 = 0;
        for(auto child : adjList[node]) {
            if(child == parent) continue;
            int val = dfs1(child, node);
            int dist = (child % 2 == 0) ? 2 : 1;
            int totalDist = dist + val;
            if(totalDist >= currMax1) {
                currMax2 = currMax1;
                currMax1 = totalDist;
            } else if(totalDist > currMax2) {
                currMax2 = totalDist;
            }
        }
        max1[node] = currMax1;
        max2[node] = currMax2;
        return currMax1;
    
    }

    void dfs2(int node , int parent, int maxFromParent,vector<int>&ans){
        ans[node] = max(max1[node],maxFromParent);
        for(int child:adjList[node]){
            if(child!=parent){
                int toChild =(child%2==0)?2:1;
                int toParent= (node%2==0)?2:1;
                int maxDistNotPassingThroughChild = (toChild + max1[child] == max1[node]) ? max2[node] : max1[node];
                dfs2(child,node,toParent+max(maxFromParent,maxDistNotPassingThroughChild),ans);

            }
        }


    }




    vector<int> timeTaken(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        max1.resize(n,0);
        max2.resize(n,0);
        adjList.resize(n);

        for(auto i:edges){
            int u = i[0];
            int v = i[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

         dfs1(0,-1);

        
        vector<int> ans(n,0);
        dfs2(0,-1,0,ans);
        return ans;
    }
};