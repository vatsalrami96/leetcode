// Last updated: 9/24/2025, 2:15:45 AM
class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> stringAIdx;
        vector<int> stringBIdx;
        int n = a.size();
        int m = b.size();
        int i=0;
        while(i+n<=s.size() ){
            if(s[i]==a[0]){
                int j=0;
                while(j<a.size()&& j<s.size() &&s[i]==a[j]){
                    i++;
                    j++;
                }
                if(j==a.size()) stringAIdx.push_back(i-a.size());
            }
            else{
                i++;
            }
        }
        int l=0;
        while(l+m<=s.size() ){
            if(s[l]==b[0]){
                int j=0;
                while(j<b.size()&& j<s.size() &&s[l]==b[j]){
                    l++;
                    j++;
                }
                if(j==b.size()) stringBIdx.push_back(l-b.size());
            }
            else{
                l++;
            }
        }
        vector<int> ans;
        for(auto i :stringAIdx){
            for(auto j: stringBIdx){
                if(abs(i-j)<=k) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
        
        
    }
};