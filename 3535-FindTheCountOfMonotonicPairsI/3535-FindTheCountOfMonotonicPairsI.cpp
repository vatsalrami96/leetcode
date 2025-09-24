// Last updated: 9/24/2025, 2:15:12 AM
#define ll long long
class Solution {
    const int mod = 1e9 + 7;

public:
    int countOfPairs(vector<int>& nums) {
        
        int n = nums.size();
        ll cnt = 0;

        int dp[n][1001];
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i<= nums[0]; i++){
            dp[0][i] = 1;
        }

        for(int i = 1; i<n; i++){
            for(int prev = 0; prev <= 50; prev++){
                for(int k = prev; k <= nums[i]; k++){
                    int val = nums[i] - k;

                    if(val <= nums[i-1] - prev)
                        dp[i][k] = (dp[i][k] + dp[i-1][prev]) % mod;
                }
            }
        }

        for(int i = 0; i<= nums[n-1]; i++){
            cnt = (cnt + dp[n-1][i]) % mod;
        }

        return cnt;
        
    }
        
};