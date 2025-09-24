// Last updated: 9/24/2025, 2:16:27 AM
class Solution {
    public char repeatedCharacter(String s) {
         HashSet<Character> hs = new HashSet<>();
        int i=0;
        while(i<s.length())
        {
            if(hs.contains(s.charAt(i)))
            {
                return s.charAt(i);              
            }
            hs.add(s.charAt(i));
            i++;
        }
        return 'a';
        
    }
}