// Last updated: 9/24/2025, 2:16:47 AM
class Solution {
    public int longestPalindrome(String[] words) {
        
        ArrayList<String> singles = new ArrayList<>();
        HashMap<String,Integer> hm = new HashMap<>();
        int ans=0;
        
        
        for(String s : words)
        {
            String reverse = getReverse(s);
            if(s.equals(reverse))
            {
                singles.add(s);
            }
            if(hm.containsKey(reverse) && hm.get(reverse)>0)
            {
                ans+=4;
                hm.put(reverse,hm.get(reverse)-1);
            }
            else
            {
                hm.put(s,hm.getOrDefault(s,0)+1);
            }
            
            
        }
        
        for(int i=0;i<singles.size();i++)
        {
            if(hm.get(singles.get(i))>0)
            {
                return ans+2;
            }
        }
        return ans;
        
        
        
    }
    
    public String getReverse(String s)
    {
        StringBuilder sb = new StringBuilder(s);
        sb.reverse();
        return sb.toString();
        
    }
}