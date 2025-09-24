// Last updated: 9/24/2025, 2:16:46 AM
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
       vector<int> lasers;
       int ans =0;
       int prev=0;
       for(string s : bank){
           int count=0;
           for(auto c : s){
               if(c=='1')count++;
           }
           if(count==0)continue;
           if(prev==0) {
               prev=count;
               continue;
           }
           ans=ans+(prev*count);
           prev=count;
           
       } 
       return ans;
    }
};