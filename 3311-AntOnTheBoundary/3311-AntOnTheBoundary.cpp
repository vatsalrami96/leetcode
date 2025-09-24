// Last updated: 9/24/2025, 2:15:34 AM
class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int ans=0;
        int sum=0;
        for(auto i:nums){
            sum+=i;
            if(sum==0) ans++;
        }
        return ans;
    }
};