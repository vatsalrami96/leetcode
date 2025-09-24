// Last updated: 9/24/2025, 2:16:55 AM
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==0) return nums;
        vector<int> result(n,-1);
        if(n<=2*k) return result;
        int l=0;
        int r=0;
        long long sum=0;
        while(r<=2*k)sum+=nums[r],r++;
        int p=k;

        while(r<n){
            result[p++]=sum/((2*k)+1);
            sum-=nums[l++];
            sum+=nums[r++];
        }
        result[p]=sum/((2*k)+1);


        return result;

    }
};

// /. handle some edge cases

// // first and  last k elemnts will be -1
// // k to <n-3


// 0-2*k+1

//2-5


