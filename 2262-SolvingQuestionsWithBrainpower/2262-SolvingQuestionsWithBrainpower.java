// Last updated: 9/24/2025, 2:16:43 AM
class Solution {
    public long mostPoints(int[][] questions) {
       long[] dp = new long[questions.length];
        dp[questions.length-1]=questions[questions.length-1][0];

        for(int index = questions.length-2;index>=0;index--)
        {   
            long notPick=0+dp[index+1];
            long pick=questions[index][0];
            if(index+questions[index][1]+1<questions.length)
                {
                    pick=pick+dp[index+questions[index][1]+1];
                }
            dp[index]=Math.max(notPick,pick);
        }

        return dp[0];

    }
}