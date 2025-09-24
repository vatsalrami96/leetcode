// Last updated: 9/24/2025, 2:15:16 AM
class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans=0;
        int n =nums.size();
        int i=0;

        for(int j=1;j<n;j++){
            if(nums[j]>nums[i] || j==n-1){
                ans=ans+(long long) (j-i)*nums[i];
                i=j;
            }
        }
        return ans;
    }
};






