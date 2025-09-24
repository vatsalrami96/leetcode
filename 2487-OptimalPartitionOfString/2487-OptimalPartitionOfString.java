// Last updated: 9/24/2025, 2:16:22 AM
class Solution {
    public int partitionString(String s) {
        int count =1;
        boolean[] dp = new boolean[27];
        Set<Character> set = new HashSet<>();

        for(int i=0;i<s.length();i++)
        {
            if(!set.contains(s.charAt(i)))
            {
              set.add(s.charAt(i));   
            }
            else
            {
                set.clear();
                count++;
                set.add(s.charAt(i));
            }
        }

        return count;

    }
}