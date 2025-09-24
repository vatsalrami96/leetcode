// Last updated: 9/24/2025, 2:15:10 AM
class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();
        int a=0;
        for(int i=0;i<n;i++){
            int cZero=0;
            int cOne=0;
            for(int j=i;j<n;j++){
                if(s[j]=='1') cOne++;
                else cZero++;
                cout<<cZero <<" "<<cOne<<endl;
                if(cOne<=k || cZero<=k) a++;
            }
        }
        return a;
    }
};

