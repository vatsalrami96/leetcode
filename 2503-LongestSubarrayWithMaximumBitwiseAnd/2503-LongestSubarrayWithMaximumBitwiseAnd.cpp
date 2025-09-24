// Last updated: 9/24/2025, 2:16:18 AM
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=1;
        for(auto i:nums) maxi = max(maxi,i);
        int n = nums.size();
        int l,r=0;
        int s=1;
        while(r<n){
            if(nums[r]==maxi){
                s=max(s,r-l+1);
                r++;
                
            }else{
                r++;
                while(l<r) l++;
            }
        }
        return s;
    }
};

//find the max;
//find the longest subbaray that has all elements as max




