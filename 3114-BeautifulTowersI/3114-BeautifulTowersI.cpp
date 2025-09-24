// Last updated: 9/24/2025, 2:15:56 AM
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {

        long long ans =0;
        
        for(int i=0;i<maxHeights.size();i++){
            stack<int> stack;
            long long localAns=0;
            stack.push(maxHeights[i]);
            localAns+=maxHeights[i];
            for(int j=i+1;j<maxHeights.size();j++){
                if(stack.top()>=maxHeights[j]){
                    stack.push(maxHeights[j]);
                    localAns+=maxHeights[j];
                }else{
                    long long value = stack.top();
                    stack.push(value);
                    localAns+=value;
                }
            }
            stack.push(maxHeights[i]);
            for(int k=i-1;k>=0;k--){
                if(stack.top()>=maxHeights[k]){
                    stack.push(maxHeights[k]);
                    localAns+=maxHeights[k];
                }else{
                    long long value = stack.top();
                    stack.push(value);
                    localAns+=value;
                }
            }
            ans=max(ans,localAns);
        }
        return ans;
    }
};