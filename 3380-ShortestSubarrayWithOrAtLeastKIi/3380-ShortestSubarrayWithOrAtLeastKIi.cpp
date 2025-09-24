// Last updated: 9/24/2025, 2:15:32 AM
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans =1e9;
        int n = nums.size();
        vector<int>vec(32,0);
        int l=0;
        int r=0;
        while(r<n){
            update(vec,nums[r],1);
            while(l<=r && getDecimalValue(vec)>=k){
                ans=min(ans,r-l+1);
                update(vec,nums[l],-1);
                l++;
            }
            r++;
        }
        if(ans==1e9) return -1;
        return ans;
    }

    void update(vector<int>&vec,int num ,int value){
        for(int i=0;i<32;i++){
            if((num>>i) &1) vec[i]+=value;
        }
    }

    int getDecimalValue(vector<int>&vec){
        int value=0;
        for(int i=0;i<32;i++){
            if(vec[i]>0){
                value = value | (1<<i);
            }
        }
        return value;
    }
};


