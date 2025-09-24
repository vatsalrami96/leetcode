// Last updated: 9/24/2025, 2:16:15 AM
class Solution {
public:
    int pivotInteger(int n) {
        vector<int> prefix(n+1);
        vector<int> suffix(n+1);
        int sum=0;
        for(int i=1;i<=n;i++){
            prefix[i] = sum+i;
            sum=prefix[i];
        }

        sum=0;
        for(int i=n;i>=1;i--){
            suffix[i]=sum+i;
            sum=suffix[i];
        }

        for(int i=1;i<=n;i++){
            if(prefix[i]==suffix[i]) return i;
        }
        return -1;
    }
};