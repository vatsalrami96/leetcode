// Last updated: 9/24/2025, 2:15:46 AM
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> freq;
        for(auto i: nums) freq[i]++;
        int ans=0;
        int maxi=0;
        for(auto p:freq){
            cout<<p.second<<endl;
            if(p.second>maxi) {
                maxi=p.second;
                ans=p.second;
            }
            else if(p.second==maxi) {
               // maxi = p.second;
                ans+=p.second;
            }
        }
        return ans;
        
    }
};