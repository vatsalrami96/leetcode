// Last updated: 9/24/2025, 2:16:45 AM
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        nums.resize(2*n);
        int totalOnes=0;
        int ans=1e9;
        for(int i=0;i<n;i++){
            nums[n+i]=nums[i];
            if(nums[i]==1) totalOnes++;
        }

        int l=0;
        int r=totalOnes-1;
        int countOnes=0;
        int countZeroes=0;
        for(int i=l;i<=r;i++){
            if(nums[i]==0) countZeroes++;
            else countOnes++;
        }
        ans=min(ans,countZeroes);
        while(r<nums.size()-1){
            if(nums[l]==0) countZeroes--;
            else countOnes--;
            l++;
            r++;
            if(nums[r]==0) countZeroes++;
            else countOnes++;
            ans=min(ans,countZeroes);

        }

        return ans;

        
    }
};