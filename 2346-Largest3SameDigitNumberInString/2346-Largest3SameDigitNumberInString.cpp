// Last updated: 9/24/2025, 2:16:38 AM
class Solution {
public:
    string largestGoodInteger(string num) {
        string ans ="";
        for(int i=0;i<num.size();i++){
            int count =0;
            int j;
            for(j=i;j<num.size();j++){                
                if(num[i]!=num[j]){
                    break;
                }
                count++;
            }
            if(count==3&& (ans.size()==0 ||num[i]>ans[0])){
                ans="";
                for(int k=0;k<3;k++){
                    ans+=num[i];
                }
            }

        }
        return ans;
    }
};