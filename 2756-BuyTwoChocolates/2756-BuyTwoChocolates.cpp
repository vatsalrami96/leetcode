// Last updated: 9/24/2025, 2:16:04 AM
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int s=1e9;
        int ss=1e9+1;
        for(auto i:prices){
            if(i<s){
                ss=s;
                s=i;
            }
            else if(i<ss){
                ss=i;
            }
        }
        return money-s-ss>=0?money-s-ss:money;
    }
};