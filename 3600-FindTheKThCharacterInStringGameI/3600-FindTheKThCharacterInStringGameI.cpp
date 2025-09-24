// Last updated: 9/24/2025, 2:15:09 AM
class Solution {
public:
    char kthCharacter(int k) {
        

        string s ="a";
        while(s.size()<k){
            string t="";
            for(int i=0;i<s.size();i++){
                char c = s[i];
                char n = s[i]+1;
                t+=n;
            }
            s=s+t;
        }

        return s[k-1];
    }
};


