// Last updated: 9/24/2025, 2:15:38 AM
class Solution {
public:
    long long flowerGame(int n, int m) {
        if(n ==1 && m==1) return 0;
        
        long long even1 = n/2;
        long long odd1 = n-even1;
        
        long long even2 = m/2;
        long long  odd2 = m-even2;
        
        return odd1*even2 + even1*odd2;
        
        
        
    }
};