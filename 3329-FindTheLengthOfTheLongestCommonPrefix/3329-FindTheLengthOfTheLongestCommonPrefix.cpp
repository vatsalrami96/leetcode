// Last updated: 9/24/2025, 2:15:33 AM
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> uset;
        for(auto i:arr1){
            string t = to_string(i);
            for(int j=0;j<t.size();j++){
                uset.insert(t.substr(0,j+1));
            }
        }
        int ans=0;
        for(auto i:arr2){
            string t = to_string(i);
            for(int j=0;j<t.size();j++){
                string f = t.substr(0,j+1);
                int n =f.size();
                if(uset.find(f)!=uset.end()){
                    ans=max(ans,n);
                }
            }
        }

        return ans;
    }
};