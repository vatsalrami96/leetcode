// Last updated: 9/24/2025, 2:15:57 AM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> count;
        for(auto i:nums){
            count[i]+=1;
        }
        int operations=0;
        for(auto p:count){
            int rem=p.second;
            if(rem==1)return -1;
            operations+=rem/3;
            rem=rem%3;
            
            if(rem!=0)operations++;            
        }
        return operations;
    }
};