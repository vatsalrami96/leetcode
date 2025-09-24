// Last updated: 9/24/2025, 2:15:29 AM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int c=0;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]==0){
                nums[i]=1;
                nums[i+1]^=1;
                nums[i+2]^=1;
                c++;
            }
        }

        for(auto i:nums) if( i==0) return -1;
        return c;
    }
};