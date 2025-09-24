// Last updated: 9/24/2025, 2:16:54 AM
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteMiddle(ListNode head) {
        
        ListNode pre = null;
        ListNode slow = head;
        ListNode fast = head;
        
        if(head.next==null)
        {
            return null;
        }
        
        
        while(fast.next!=null && fast.next.next!=null)
        {
            fast= fast.next.next;
            pre=slow;
            slow = slow.next;
            
            
        }
        if(fast.next!=null)
        {   
            pre=slow;
            slow=slow.next;
        }
        
      
        
        pre.next=pre.next.next;
      //  slow.next=null;
        
        
        return head;
        
        
        
    }
}