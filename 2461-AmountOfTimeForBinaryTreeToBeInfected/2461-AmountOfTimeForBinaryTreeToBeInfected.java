// Last updated: 9/24/2025, 2:16:29 AM
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int amountOfTime(TreeNode root, int start) {
        
         HashMap<Integer,TreeNode> parentMap = new HashMap<>();
        Queue<TreeNode> queue = new LinkedList<>();
        HashSet<TreeNode> visited = new HashSet<>();
      
        
        
        
        queue.offer(root);
        while(!queue.isEmpty())
        {
            TreeNode current = queue.poll();
            if(current.left!=null)
            {
                parentMap.put(current.left.val,current);
                queue.offer(current.left);
            }
            if(current.right!=null)
            {
                parentMap.put(current.right.val,current);
                queue.offer(current.right);
            }
            
        }
        
        
        TreeNode initial = dfs(root,start);
        
        if(initial.left==null && initial.right==null && !parentMap.containsKey(initial.val))
        {
            return 0;
        }
        int ans =-1;
        queue.offer(initial);
        
        
        while(!queue.isEmpty())
        {
            int size = queue.size();
            System.out.println(size);
            ans++;
            for(int i=0;i<size;i++)
            {   
                
                TreeNode current = queue.poll();
                System.out.print(current.val);
                
                visited.add(current);
                if(parentMap.containsKey(current.val) && !visited.contains(parentMap.get(current.val)) )
                {
                    TreeNode parent = parentMap.get(current.val);
                     queue.offer(parent);
                }
                if(current.left!=null  && !visited.contains(current.left) )
                {
                    queue.offer(current.left);
                
                }
                if(current.right!=null  && !visited.contains(current.right) )
                {
                    queue.offer(current.right);
                }
            }
            
            
        }
        
        return ans ;
        
    }
    
    TreeNode dfs(TreeNode node,int start)
    {
        if(node==null)
        {
            return null;
        }
        if(node.val==start)
        {
            return node;
        }
        TreeNode left = dfs(node.left,start);
        TreeNode right = dfs(node.right,start);
        if(left!=null || right!=null)
        {
            if(left!=null)
            {
                return left;
            }
            return right;
        }
        return null;
    }
}