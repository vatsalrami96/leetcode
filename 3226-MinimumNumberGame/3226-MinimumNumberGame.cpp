// Last updated: 9/24/2025, 2:15:53 AM
class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int> ans(nums.size());
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i%2==0) ans[i+1]=nums[i];
            else ans[i-1]=nums[i];
        }
        
        return ans;
    }
};