// Last updated: 9/24/2025, 2:15:22 AM
class Solution {
public:
    int minChanges(int n, int k) {
        int count = 0;
        int copy = n;
    
    while (n > 0 || k > 0) {
        int bitn = n & 1;
        int bitk = k & 1;
        
        if (bitn == 1 && bitk == 0) {
            count++;
        } else if (bitn == 0 && bitk == 1) {
            return -1;  
        }
        
        n >>= 1;
        k >>= 1;
    }
    
    
    if (copy < k) {
        return -1;
    }
    
    return count;
        
    }
};