// Last updated: 9/24/2025, 2:16:42 AM
class Solution {
    public int prefixCount(String[] words, String pref) {
        
        int l=pref.length();
        int count=0;
        for(int i=0;i<words.length;i++)
        {   
            if(pref.length()<=words[i].length())
            {
                      
                      if(words[i].substring(0,l).equals(pref))
                      {
                          count++;
                      }             
                    
            }
            
        }
        
        return count;
        
    }
}