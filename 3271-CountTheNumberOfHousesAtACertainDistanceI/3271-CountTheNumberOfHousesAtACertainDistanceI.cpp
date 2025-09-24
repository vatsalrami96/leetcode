// Last updated: 9/24/2025, 2:15:40 AM
class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> adjList(n);
        for(int idx=0;idx<n;idx++ ){
            if(idx-1>=0){
                adjList[idx].push_back(idx-1);
            }
            if(idx+1<n){
                adjList[idx].push_back(idx+1);
            }
        }
        if(x!=y){
            adjList[x-1].push_back(y-1);
            adjList[y-1].push_back(x-1);
        }
        unordered_map<int,int> count;
        for(int i=0;i<n;i++){            
            dijkshtra(i,adjList,n,count);            
        }
        
        vector<int> ans(n);
        for(auto i:count){
            ans[i.first-1]=i.second;
        }
        
        while(ans.size()<n){
            ans.push_back(0);
        }
        
        
        return ans;
        
        
        
        
    }
    void dijkshtra(int source, vector<vector<int>> &adjList, int n,unordered_map<int,int> &count){
        vector<int> dist(n,1e9);
        dist[source] =0;
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > pq;
        pq.push({source,0});
        //visited[source-1]=true;
        while(!pq.empty()){
            auto current = pq.top();
            pq.pop();
            for(auto neighNode : adjList[current.first]){
                int currDis = current.second+1;
                if(currDis < dist[neighNode]  ){
                    dist[neighNode] = currDis;
                    pq.push({neighNode,currDis });
                }
            }
        }        
        for(int i=0;i<n;i++){
            if(dist[i]!=0){
                count[dist[i]]++;
            }
        }
        
        
    }
};