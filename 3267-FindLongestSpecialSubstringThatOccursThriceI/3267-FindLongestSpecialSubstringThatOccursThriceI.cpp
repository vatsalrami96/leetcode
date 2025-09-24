// Last updated: 9/24/2025, 2:15:41 AM
class Solution {
public:
    bool equal(string s){
        for(int i=1;i<s.size();i++){
            if(s[i]!=s[i-1]) return false;
        }
        return true;
    }
    int maximumLength(string s) {
        int n = s.size();
        int ans =-1;
        map<string,int>map;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                string temp = s.substr(i,j-i+1);
                cout<<temp<<",";
                map[temp]++;
            }
            cout<<endl;
        }
        for(auto p:map){
            int size = p.first.size();
            if(p.second>=3 && equal(p.first))ans=max(ans,size);
        }
        return ans;
    }
};