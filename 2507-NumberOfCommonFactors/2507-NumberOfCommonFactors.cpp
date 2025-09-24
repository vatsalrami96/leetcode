// Last updated: 9/24/2025, 2:16:17 AM
class Solution {
public:
    int commonFactors(int a, int b) {
        int count =1;
        for(int num = 2 ; num<=min(a,b);num++){
            if(a%num==0 && b%num==0) count++;
        }
        return count;
    }
};