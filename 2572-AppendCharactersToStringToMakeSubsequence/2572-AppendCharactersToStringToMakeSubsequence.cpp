// Last updated: 9/24/2025, 2:16:14 AM
class Solution {
public:
    int appendCharacters(string s, string t) {
        int p1=0;
        int p2=0;
        while(p1<s.size() && p2<t.size()){
            if(s[p1]==t[p2]) {
                p1++;
                p2++;
            }
            else{
                p1++;
            }

        }

        return t.size()-p2;
    }
};