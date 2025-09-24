// Last updated: 9/24/2025, 2:15:14 AM
class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        vector<vector<int>> grid(n,vector<int>(n,0));
        int i=0;
        int j=0;
        for(auto x:commands){
            if(x=="UP"){
                i--;;
            }
            if(x=="RIGHT"){
                j=j+1;
            }
            if(x=="DOWN"){
                i=i+1;
            }
            if(x=="LEFT"){
                j=j-1;
            }
        }

        return i*n+j;


       
    }
};