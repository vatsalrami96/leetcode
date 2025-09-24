// Last updated: 9/24/2025, 2:16:12 AM
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<int> st(nums.begin(),nums.end());
        int n = nums.size();
        int longestStreak=1;

        for(auto i:nums){
            int currStreak=0;
            long long toFind= i;
            while(st.find(toFind)!=st.end()){
                currStreak++;
                if(toFind*toFind>1e5) break;
                toFind=toFind*toFind;
            }
            longestStreak=max(longestStreak,currStreak);
        }

        if(longestStreak ==1 ) return -1 ;
        return longestStreak;
        
    }
};



