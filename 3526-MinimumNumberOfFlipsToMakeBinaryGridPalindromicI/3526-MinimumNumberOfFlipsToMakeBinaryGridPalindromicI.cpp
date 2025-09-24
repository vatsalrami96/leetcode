// Last updated: 9/24/2025, 2:15:16 AM
class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int r=0;
        int c=0;

        for(auto i:grid){
            for(int j=0;j<i.size()/2;j++){
                if(i[j]!=i[m-j-1]) r++;
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n/2;j++){
                if(grid[j][i]!=grid[n-j-1][i]) c++;
            }
        }

        return min(r,c);
        
    }
};