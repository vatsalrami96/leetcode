// Last updated: 9/24/2025, 2:15:59 AM
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count =0;
        for(char c:s){
            if(c=='1'){
                count++;
            }
        }
        
        int length = s.size()-1;
        string ans ="1";
        string subans;
        count--;
        while(length>0){
            if(count>0){
                subans+='1';
                count--;
            }
            else{
                subans+='0';
                
            }
            length--;
        }
        
        return subans+ans;
        
    }
};