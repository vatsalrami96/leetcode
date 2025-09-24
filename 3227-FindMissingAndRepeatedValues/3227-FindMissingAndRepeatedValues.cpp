// Last updated: 9/24/2025, 2:15:52 AM
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> sorted;
        int n = grid.size();
        vector<int> ans (2);
        sorted.push_back(0);
        sorted.push_back(n*n+1);
        

        for(auto r:grid){
            for(auto c:r){
                sorted.push_back(c);
            }
        }
        sort(sorted.begin(),sorted.end());

        for(int i=1;i<sorted.size();i++){
            if(sorted[i]-sorted[i-1]==0) ans[0]=sorted[i];
            if(sorted[i]-sorted[i-1]==2) ans[1]=(sorted[i] +sorted[i-1])/2;
        }

        return ans;
        
    }
};


// 0 1 2 2 3 5