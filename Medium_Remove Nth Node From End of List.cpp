/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return NULL;
        }
        
        int gap = 0;
        
        ListNode* itv_h = head;
        ListNode* itv_t = head;
        while(itv_t != NULL && gap <= n){
            itv_t = itv_t->next;
            gap++;
        }
        
        while(itv_t != NULL){
            itv_t = itv_t->next;
            itv_h = itv_h->next;
        }
        
        if(gap <= n){
            return itv_h->next;
        }
        
        itv_h->next = itv_h->next->next;
        
        return head;
    }
};