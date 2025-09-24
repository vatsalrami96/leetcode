// Last updated: 9/24/2025, 2:16:50 AM
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size();
        int spaceIdx=0;
        if(spaces.size()==0) return s;
        string res="";
        for(int i=0;i<n;i++){
            if(spaceIdx < spaces.size() && i==spaces[spaceIdx]) {
                res+=" ";
                spaceIdx++;
            }
            res+=s[i];
        }
        return res;
        
    }
}; 



// LeetcodeHelpsMeLearn
//         1    1 1 