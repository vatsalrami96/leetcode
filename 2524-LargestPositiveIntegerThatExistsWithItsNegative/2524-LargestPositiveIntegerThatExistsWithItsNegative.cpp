// Last updated: 9/24/2025, 2:16:16 AM
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> seen(1e3+1,0);
        int max=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0) seen[abs(nums[i])]=-1;
            if(nums[i]>0 && seen[nums[i]] ==-1) max = nums[i];   
        }

        return max;

    }
};


