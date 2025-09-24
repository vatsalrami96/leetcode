// Last updated: 9/24/2025, 2:15:36 AM
class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n =word.size(); //7
        string s="";
        for(auto c:word){
            s+=c;
        }
        int ans=1;
        for(int i=k;i<n;i+=k){
            if(isEqual(i,word,n)) return ans;
            ans++;
        }
        return ans;
    }
    bool isEqual(int idx, string s,int n){
        int j=0;
        for(int i=idx; i<n;i++){
            if(s[i]!=s[j]){
                cout <<i;
                return false;
            }
            j++;
        }
               
        return true;
    }
};