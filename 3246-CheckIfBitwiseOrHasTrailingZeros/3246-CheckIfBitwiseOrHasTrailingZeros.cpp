// Last updated: 9/24/2025, 2:15:44 AM
class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int count=0;
        for(auto i : nums){
            if(i%2==0) count++;
        }
        
        if(count>=2)return true;
        return false;
        
    }
};