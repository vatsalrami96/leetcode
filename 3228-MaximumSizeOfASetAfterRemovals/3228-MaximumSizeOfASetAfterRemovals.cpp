// Last updated: 9/24/2025, 2:15:51 AM
class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n =nums1.size();
        set<int> setA;
        set<int> setB;
        set<int> tempB;
        set<int> setCommon;
        
        for(auto i : nums1) setA.insert(i);
        for(auto i : nums2) tempB.insert(i);
        for(auto i : tempB){
            if(setA.find(i)==setA.end()) setB.insert(i);
            else{
                setA.erase(i);
                setCommon.insert(i);
            }
        }
        int ans =0;
        int bestAns= n;
        
        int i=setA.size();
        int j=setB.size();
        int k =setCommon.size();
        
        (i>=n/2)? ans+=(n/2):ans+=i;
        (j>=n/2)? ans+=(n/2):ans+=j;
        if(ans==bestAns) return bestAns;
        (ans+k>=bestAns)? ans=bestAns:ans+=k;
        return ans;
    }
};