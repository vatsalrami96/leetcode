// Last updated: 9/24/2025, 2:16:09 AM
class Solution {
    public int vowelStrings(String[] words, int left, int right) {
        int count=0;
        Set<Character> set = new HashSet<>();
        set.add('a');
        set.add('e');
        set.add('i');
        set.add('o');
        set.add('u');

        for(int i=left;i<=right;i++)
        {
            if(set.contains(words[i].charAt(0))&&set.contains(words[i].charAt(words[i].length()-1)) )
            {
                count++;
            }
        }
        return count;
    }
}