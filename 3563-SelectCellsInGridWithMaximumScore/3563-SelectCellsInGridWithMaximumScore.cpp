// Last updated: 9/24/2025, 2:15:11 AM
class Solution {
public:
    int dp[101][1025];
    int have[101][10];
    int maxScore(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                have[grid[i][j]][i]=1;
            }
        }
        int ans=helper(1,0,r);
        return ans;
        
    }

    int helper(int num, int bitmask, int r){
        if(bitmask==(1<<r)-1) return 0;
        if(num>100) return 0;
        if(dp[num][bitmask]!=-1) return dp[num][bitmask];
        int ans=0;
        for(int i=0;i<r;i++){
            if(have[num][i]){
                if((bitmask & (1<<i))) continue;
                int tempmask = bitmask | (1<<i);
                ans=max(ans,num+helper(num+1,tempmask,r));
            }
        }
        ans=max(ans,helper(num+1,bitmask,r));

        return dp[num][bitmask]=ans;
    }
};