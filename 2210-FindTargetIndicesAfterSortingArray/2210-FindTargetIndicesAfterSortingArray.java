// Last updated: 9/24/2025, 2:16:56 AM
class Solution {
    public List<Integer> targetIndices(int[] nums, int target) {
        ArrayList<Integer> res = new ArrayList<Integer>();       
        int k=nums.length;
        Arrays.sort(nums);
        
        for(int i=0;i<k;i++)
        {
            if(nums[i]==target)
            {
                res.add(i);
            }
        }
        return res;
        
    }
}