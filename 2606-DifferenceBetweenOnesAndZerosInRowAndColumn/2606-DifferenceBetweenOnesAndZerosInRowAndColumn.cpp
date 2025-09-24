// Last updated: 9/24/2025, 2:16:12 AM
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        

        int n =grid.size();
        int m = grid[0].size();

        vector<int> OneRow;
        vector<int> OneCol;
        vector<int> ZeroRow;
        vector<int> ZeroCol;

        for(int i=0;i<n;i++){
            int countZ=0;
            int countO=0;
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) countZ++;
                if(grid[i][j]==1) countO++;
            }
            ZeroRow.push_back(countZ);
            OneRow.push_back(countO);
        }
        for(int j=0;j<m;j++){
            int countZ=0;
            int countO=0;
            for(int i=0;i<n;i++){
                if(grid[i][j]==0) countZ++;
                if(grid[i][j]==1) countO++;
            }
            OneCol.push_back(countO);
            ZeroCol.push_back(countZ);
        }
        vector<vector<int>> ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j] = OneRow[i]+OneCol[j]-ZeroRow[i]-ZeroCol[j];
            }
        }
        return ans;
    }
};