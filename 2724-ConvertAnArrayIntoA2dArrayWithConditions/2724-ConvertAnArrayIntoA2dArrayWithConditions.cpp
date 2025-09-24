// Last updated: 9/24/2025, 2:16:08 AM
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> freq(201,0);
        vector<vector<int>> ans;
        for(auto i:nums)freq[i]++;
        while(true){
            bool flag =false;
            vector<int>temp;
            for(int i=1;i<freq.size();i++){
                if(freq[i]!=0){
                    temp.push_back(i);
                    freq[i]--;
                    flag=true;
                }
            }
            if(!flag) break;
            ans.push_back(temp);
        }
        return ans;
    }
};