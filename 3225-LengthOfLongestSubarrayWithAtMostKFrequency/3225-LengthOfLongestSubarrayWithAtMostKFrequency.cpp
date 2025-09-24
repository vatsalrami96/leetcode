// Last updated: 9/24/2025, 2:15:54 AM
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int start= 0;
        int ans=0;
        int end;
        for(end=0;end<nums.size();end++){
            freq[nums[end]]++;
            if(freq[nums[end]]>k){
                ans=max(ans,end-start);
                while(freq[nums[end]]>k){
                   freq[nums[start]]--;
                    start++;
                }
            }
        }
        ans=max(ans,end-start);
        
        return ans;
    }
};