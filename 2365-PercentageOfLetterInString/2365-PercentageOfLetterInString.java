// Last updated: 9/24/2025, 2:16:36 AM
class Solution {
    public int percentageLetter(String s, char letter) {
        
        int length = s.length();
        int count =0;
        
        for(int ch =0; ch <length ; ch++)
        {
         if(s.charAt(ch)==letter)
         {
             count++;
         }
        }
        
       return (count*100)/length;
    }
}