// Last updated: 9/24/2025, 2:15:17 AM
class Solution {
public:
    //long long  dp[5][100001];
    long long maxScore(vector<int>& a, vector<int>& b) {
        // memset(dp,-1,sizeof(dp));
        // return solve(0,0,a,b);

        int n = b.size();
        long long dp [5][n+1];
        memset(dp,0,sizeof(dp));
        // Initialize base cases
        for (int i = 0; i < 5; i++) {
            dp[i][n] = -1e12;  // No valid pairings possible for all rows except the last
        }
        dp[4][n] = 0;  // The base case when both i == 4 and j == n (end of both arrays)

        // Bottom-up dynamic programming
        for (int i = 3; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                long long pick = (long long)a[i] * b[j] + dp[i+1][j+1];  // Case when we pick a[i] * b[j]
                long long notpick = dp[i][j+1];  // Case when we don't pick a[i] * b[j]
                dp[i][j] = max(pick, notpick);  // Max of picking or not picking
            }
        }





        return dp[0][0];
    }

    // long long solve(int i,int j,vector<int>& a, vector<int>& b){
    //     if(i==4) return 0;
    //     if(j>=b.size()) return -1e12;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     long long ans =-1e12;
    //     long long pick = (long long)a[i] * b[j] + solve(i+1, j+1, a, b);
    //     long long notpick = solve(i,j+1,a,b);
    //     return dp[i][j]=max(pick,notpick);

    // }
};




