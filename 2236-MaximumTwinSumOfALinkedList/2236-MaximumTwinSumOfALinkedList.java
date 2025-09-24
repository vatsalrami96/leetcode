// Last updated: 9/24/2025, 2:16:48 AM
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
    public int pairSum(ListNode head) {
        ListNode fast=head;
        ListNode slow=head;
       
        while(fast!=null && fast.next!=null)
        {
            slow=slow.next;
            fast=fast.next.next;
            

        }
       
        ListNode future=null;
        ListNode prev=null;
        ListNode current =slow;
        //if(slow.next!=null && slow.next.next!=null) fast=slow.next.next;
       // slow.next=null;
         while(current!=null)
        {
            // current.next=slow;
            // slow=current;
            // current=fast;
            // if(fast!=null && fast.next!=null) fast=fast.next;

            future = current.next;
            current.next=prev;
            prev=current;
            current=future;
        }

        ListNode first=head;
        ListNode last=prev;
        int ans =-1;
        while(last!=null)
        {
            ans=Math.max(ans,first.val+last.val);
            first=first.next;
            last=last.next;
        }

        return ans;
    }
}