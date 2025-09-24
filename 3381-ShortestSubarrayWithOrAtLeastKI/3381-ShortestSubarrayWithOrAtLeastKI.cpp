// Last updated: 9/24/2025, 2:15:31 AM
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans=1e9;
        
        for(int i=0;i<n;i++){
            int orSum =0;
            for(int j=i;j<n;j++){
                orSum|=nums[j];
                if(orSum>=k){
                    ans=min(ans,j-i+1);
                }
            }
        }
        if(ans==1e9) return -1;
        return ans;
    }
};

