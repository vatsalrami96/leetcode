// Last updated: 9/24/2025, 2:15:29 AM
class Solution {
public:
    bool doesAliceWin(string s) {
        set<char> st{'a','e','i','o','u'};
        int count=0;
        for(auto i:s){
            if(st.find(i)!=st.end()) count++;
        }
        if(count==0) return false;
        return true;
    }
};