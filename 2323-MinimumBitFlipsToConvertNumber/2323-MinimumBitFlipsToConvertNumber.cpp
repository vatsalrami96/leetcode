// Last updated: 9/24/2025, 2:16:39 AM
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int val = start^goal;
        int c=0;
        while(val){
            c+= val&1;
            val=val>>1;
        }

        return c;
    }
};

