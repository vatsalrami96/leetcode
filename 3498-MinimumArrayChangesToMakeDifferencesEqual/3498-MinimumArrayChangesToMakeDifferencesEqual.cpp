// Last updated: 9/24/2025, 2:15:25 AM
class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        vector<int>freq(k+1);
        vector<int> threshold;
        int n = nums.size();

        for(int i=0;i<nums.size()/2;i++){
            int cd= abs(nums[i]-nums[n-i-1]);
            freq[cd]++;
            int a = max(nums[i],nums[n-i-1]);
            int b = k-min(nums[i],nums[n-i-1]);
            threshold.push_back(max(a,b));
        }

        n/=2;
        int ans=1e9;

        sort(threshold.begin(),threshold.end());
        for(int i=0;i<freq.size();i++){
            int ones = n-freq[i]; ///this much will require atleast one operation
            int twos = lower_bound(threshold.begin(),threshold.end(),i)-threshold.begin();//they will def require two operation 

            //for ones we do +1 for two change we do +2 but in ones we also account some pair that requie two changes so we just have to add +1 to the pairs that require 2 changes
            ans=min(ans,ones+twos); 

        }
        return ans;
    }
};