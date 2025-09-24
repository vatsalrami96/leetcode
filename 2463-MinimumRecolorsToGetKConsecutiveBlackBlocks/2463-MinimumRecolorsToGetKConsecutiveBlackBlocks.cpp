// Last updated: 9/24/2025, 2:16:25 AM
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int wCount=0;
        int bCount=0;
        int ans = k;

        int r=0;
        for(;r<k;r++){
            if(blocks[r]=='W') wCount++;
            else bCount++;
        }
        ans=min(ans,wCount);
        int l=0;
        int n = blocks.size();
        while(r<n){
            if(blocks[l]=='W') wCount--;
            else bCount--;
            l++;

            if(blocks[r]=='W') wCount++;
            else bCount++;
            ans=min(ans,wCount);
            r++;
        }



        return ans;
    }
};


