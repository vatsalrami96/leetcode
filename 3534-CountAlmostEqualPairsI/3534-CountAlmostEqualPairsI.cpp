// Last updated: 9/24/2025, 2:15:13 AM
class Solution {
public:



    int helper(int num1,int num2){
        string s1 = to_string(num1);
        string s2 = to_string(num2);
        int n1=s1.size();
        int n2=s2.size();
        int maxN= max(n1,n2);
        while(s1.size()!=maxN){
            s1='0'+ s1;
        }
        while(s2.size()!=maxN){
            s2='0' + s2;
        }
        unordered_map<char,int>umap1,umap2;
        int mm=0;
        for(int i=0;i<maxN;i++){
            if(s1[i]!=s2[i]) mm++;
            umap1[s1[i]]++;
            umap2[s2[i]]++;
        }

        return umap1==umap2 && mm<=2;
    }



    int countPairs(vector<int>& nums) {
       int ans=0;
       int n = nums.size();
       for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans+=helper(nums[i],nums[j]);
            }
       }
       
       return ans; 
    }
};