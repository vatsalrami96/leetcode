// Last updated: 9/24/2025, 2:15:20 AM
class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int ss=0;
        int ds=0;
        for(auto i:nums){
            string x = to_string(i);
            if(x.size()==1) ss+=i;
            else ds+=i;

        }
        bool ans= ss!=ds;
        cout <<ans;
        return ans;
    }
};