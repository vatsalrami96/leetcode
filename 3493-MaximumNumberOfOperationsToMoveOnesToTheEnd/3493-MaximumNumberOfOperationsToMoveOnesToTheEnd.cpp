// Last updated: 9/24/2025, 2:15:27 AM
class Solution {
public:
    int maxOperations(string s) {
        int ans=0;
        int last=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') last=i;
        }
        int prev=0;
        int countOne=0;
        for(int i=0;i<=last;i++){
           if(i>0 && s[i-1]=='1' &&s[i]=='0') {
               ans=countOne+prev;
               prev=ans;
           }if(s[i]=='1'){
               countOne++;
           } 
            
        }
        return ans;
        
        
    }
};