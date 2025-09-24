// Last updated: 9/24/2025, 2:15:48 AM
class Solution {
public:
    
    //check for current binary search query
    bool valid(long long mid, long long x, long long k){
        //number of 1's in required bit positions
        //upto the number mid
        long long sum=0;
        for(long long i=x-1;i<=53;i+=x){
            long long dividend=mid+1;
            long long patsize=(1LL<<(i+1));
            sum+=patsize/2*(dividend/patsize);
            long long rem=dividend%patsize;
            if(rem<=patsize/2) continue;
            rem%=(patsize/2);
            sum+=rem;
        }
        return sum<=k;
    }
    
    long long findMaximumNumber(long long k, int x) {
        //binary search
        long long low=1,high=1e15,mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(valid(mid,x,k)) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};