// Last updated: 9/24/2025, 2:15:19 AM
class neighborSum {
public:
    vector<vector<int>> v;
    int n;
    int m;
    neighborSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        v=grid;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         v[i][j]=grid[i][j];
        //     }
        // }
    }
    
    int adjacentSum(int value) {
        int s=0;
        int r=-1;
        int c=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==value) {
                    r=i;
                    c=j;
                    break;
                }

            }
            if (r != -1) break;
        }

        if(r==-1 && c==-1) return -1;

        if(r-1>=0)s+=v[r-1][c];
        if(c+1<m)s+=v[r][c+1];
        if(r+1<n)s+=v[r+1][c];
        if(c-1>=0)s+=v[r][c-1];

        return s;
        
        
    }
    
    int diagonalSum(int value) {
        int s=0;
        int r=-1;
        int c=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==value)  {
                    r=i;
                    c=j;
                    break;
                }

            }
            if (r != -1) break;
        }
        if(r==-1 && c==-1) return -1;

        if(r-1>=0 &&c-1>=0)s+=v[r-1][c-1];
        if(r-1>=0 && c+1<m)s+=v[r-1][c+1];
        if(r+1<n && c+1<m)s+=v[r+1][c+1];
        if(r+1<n && c-1>=0)s+=v[r+1][c-1];

        return s;
        
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */