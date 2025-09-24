// Last updated: 9/24/2025, 2:16:41 AM
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
    ListNode* mergeNodes(ListNode* head) {
        vector<int> v;
        travel(v, head->next);

        ListNode* dummy = new ListNode(0);  // Dummy node to simplify list construction
        ListNode* current = dummy;

        for (int i = 0; i < v.size(); i++) {
            ListNode* newNode = new ListNode(v[i]);
            current->next = newNode;
            current = current->next;
        }

        ListNode* newHead = dummy->next;
        delete dummy;  // Clean up the dummy node
        return newHead;
    }
    void travel(vector<int> &v,ListNode* node){
        int sum=0;
        while(node!=nullptr){
            if(node->val==0){
                v.push_back(sum);
                sum=0;
            }else{
                sum+=node->val;
            }
            node=node->next;
        }
    }
};