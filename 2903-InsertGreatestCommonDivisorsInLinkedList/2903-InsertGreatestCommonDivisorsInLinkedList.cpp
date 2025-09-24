// Last updated: 9/24/2025, 2:16:01 AM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {

        ListNode* prev=head;
        ListNode* curr=head->next;
        

        while(curr){
            int val= __gcd(prev->val,curr->val);
            ListNode* temp = new ListNode(val,curr);
            prev->next=temp;
            prev=curr;
            curr=curr->next;
            
        }

        return head;
        
        
    }
};


