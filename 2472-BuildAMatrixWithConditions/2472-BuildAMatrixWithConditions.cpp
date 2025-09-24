// Last updated: 9/24/2025, 2:16:23 AM
class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        set<vector<int>> seen;
        vector<int>edges(k+1,0);
        unordered_map<int,vector<int>> adjList;
        edges[0]=-1;
        unordered_map<int,vector<int>> order;
        for(auto i:rowConditions){
            if(seen.find(i)==seen.end()){
                edges[i[1]]++;
                adjList[i[0]].push_back(i[1]);
                seen.insert(i);
            }
        }

        queue<int>q;
        for(int i=1;i<edges.size();i++){
            if(edges[i]==0) q.push(i);
        }
        int rowCount=0;
        while(!q.empty()){
            auto i = q.front();
            q.pop();
            for(auto neigh:adjList[i]){
                edges[neigh]--;
                if(edges[neigh]==0) q.push(neigh);
            }
            order[i].push_back(rowCount++);
        }

        for(int i=1;i<edges.size();i++) if(edges[i]!=0) return {};
        // for(auto i:order){
        //     cout<<i.first<<"-";
        //     for(auto j:i.second){
        //         cout << j<<" ";
        //     }
        //     cout <<endl;
        // }
        seen.clear();
        for(int i=1;i<edges.size();i++) edges[i]=0;
        unordered_map<int,vector<int>> adjListc;
        for(auto i:colConditions){
            if(seen.find(i)==seen.end()){
                edges[i[1]]++;
                adjListc[i[0]].push_back(i[1]);
                seen.insert(i);
            }
        }
        

        //queue<int>q;
        for(int i=1;i<edges.size();i++){
            if(edges[i]==0) q.push(i);
            
        }
        int colCount=0;
       // cout<<q.size();
        while(!q.empty()){
            auto i = q.front();
            q.pop();
            for(auto neigh:adjListc[i]){
                edges[neigh]--;
                if(edges[neigh]==0) q.push(neigh);
            }
            order[i].push_back(colCount++);
        }

        for(int i=1;i<edges.size();i++) if(edges[i]!=0) return {};

        vector<vector<int>> ans(k,vector<int>(k,0));

        for(auto i:order){
            int r = i.second[0];
            int c = i.second[1];
            ans[r][c] = i.first;
        }

        

        return ans;


    }
};