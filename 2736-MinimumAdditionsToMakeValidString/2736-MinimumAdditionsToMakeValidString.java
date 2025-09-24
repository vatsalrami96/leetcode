// Last updated: 9/24/2025, 2:16:06 AM
class Solution {
    public int addMinimum(String word) {
        if(word.length()==1) return 2;
        int ans =0;
        //check for initial character
        if(word.charAt(0)=='b') ans+=1;
        if(word.charAt(0)=='c') ans+=2; 
        for(int first=0,second=1;second<word.length();first++,second++)
        {   
            if(word.charAt(first)==word.charAt(second))
            {
                ans+=2;
            } 
            else if((word.charAt(first)-word.charAt(second)== -1) ||(word.charAt(first)-word.charAt(second)==2)) 
            {
                ans+=0;
            }
            else 
            {
                ans+=1;
            }
             
        }
        //check for last character
        if(word.charAt(word.length()-1)=='a') ans+=2;
        if(word.charAt(word.length()-1)=='b') ans+=1; 

        return ans;

    }
}