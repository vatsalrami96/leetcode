// Last updated: 9/24/2025, 2:16:07 AM
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        for(auto i:details){
            int a =stoi(i.substr(11,2));
            if(a>60) ans++;
        }

        return ans;
    }
};