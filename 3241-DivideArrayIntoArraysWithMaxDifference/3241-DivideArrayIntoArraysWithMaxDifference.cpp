// Last updated: 9/24/2025, 2:15:47 AM
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());        
        for(int i=0;i<nums.size();i+=3){
            vector<int>row(3);
            row[0]=nums[i];
            if(nums[i+1]-nums[i]<=k)row[1]=nums[i+1];
            else {
                vector<vector<int>> dummy;
                return dummy;
            }
            if(nums[i+2]-nums[i+1]<=k && nums[i+2]-nums[i]<=k ) {
                    row[2]=nums[i+2];
                    ans.push_back(row);
            }
            else {
                vector<vector<int>> dummy;
                return dummy;
            }
            
        }
        return ans;
    }
};