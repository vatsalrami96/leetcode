// Last updated: 9/24/2025, 2:15:24 AM
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int>seen;
        for(auto i:nums) seen.insert(i);

        ListNode* newhead=head;
        while(seen.find(newhead->val) != seen.end()){
            newhead=newhead->next;
        }

        ListNode* curr = newhead;
        ListNode* prev = newhead;

        while(curr->next!=nullptr){
            if(seen.find(curr->next->val)==seen.end()){
                curr=curr->next;
                prev->next=curr;
                prev=curr;
            }
            else{
                curr=curr->next;
            }
        }

        prev->next=nullptr;



        return newhead;

    }
};