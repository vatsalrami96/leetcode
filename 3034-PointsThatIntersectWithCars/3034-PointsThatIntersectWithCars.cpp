// Last updated: 9/24/2025, 2:16:00 AM
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> prefix(102);
        for(auto i:nums){
            prefix[i[0]]++;
            prefix[i[1]+1]--;
        }
        int a=0;
        for(int i=1;i<=101;i++){
            prefix[i]+=prefix[i-1];
            if(prefix[i]>=1)a++;
        }

        return a;

    }
};


