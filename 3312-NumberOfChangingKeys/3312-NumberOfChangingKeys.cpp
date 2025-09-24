// Last updated: 9/24/2025, 2:15:35 AM
class Solution {
public:
    int countKeyChanges(string s) {
        int totalChange=0;
        string lowerS="";
        for(auto c:s){
            lowerS+=tolower(c);
        }
        for(int i=1;i<s.size();i++){
            if(lowerS[i]!=lowerS[i-1]) totalChange++;
        }
        return totalChange;
    }
};