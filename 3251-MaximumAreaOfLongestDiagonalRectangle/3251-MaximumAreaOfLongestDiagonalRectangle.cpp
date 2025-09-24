// Last updated: 9/24/2025, 2:15:42 AM
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int area=0;
        float maxDiag=0;
        for(auto i:dimensions){
            int length=i[0];
            int breadth=i[1];
            float diag = sqrt((length*length) + (breadth*breadth));
            cout<<diag<<endl;
            if(diag==maxDiag) {                
                area = max(area,length*breadth);
                maxDiag=diag;
            }
            else if(diag>maxDiag) {                
                area = length*breadth;
                maxDiag=diag;
            }
        }
        return area;
    }
};