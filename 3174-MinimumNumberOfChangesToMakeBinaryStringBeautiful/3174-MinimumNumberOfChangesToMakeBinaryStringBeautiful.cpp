// Last updated: 9/24/2025, 2:15:55 AM
class Solution {
public:
    int minChanges(string s) {
        int ans=0;
        int n = s.size();
        for(int i=0;i<n-1;i+=2){
            int sum=0;
            sum = (s[i]=='0') ?sum+0:sum+1;
            sum = (s[i+1]=='0') ?sum+0:sum+1;
            if(sum==1) ans+=1;
        }
        return ans;
    }
};









