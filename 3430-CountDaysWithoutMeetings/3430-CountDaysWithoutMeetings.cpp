// Last updated: 9/24/2025, 2:15:30 AM
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int ans=meetings[0][0] -1;
        int prevEnd = meetings[0][1];

        for(int i=1;i<meetings.size();i++){
            int currentStart = meetings[i][0];
            int currentEnd = meetings[i][1];

            if(currentStart>prevEnd)ans+= currentStart - prevEnd -1;
            prevEnd = max(prevEnd,currentEnd);
        }
        
        if(prevEnd < days) ans+= days-prevEnd;

        return ans;
        
    }
};


