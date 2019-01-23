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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *node, *iter;
        vector<ListNode*> node_vec(k, NULL);
        ListNode start(0);
        start.next = head;
        iter = &start;
        
        while(1){
            node = iter;
            for(int i=0; i<k; i++){
                node = node->next;
                if(node == NULL)
                    return start.next;
                node_vec[i] = node;
            }
            
            iter->next = node_vec[k-1];
            iter = node_vec[0];
            node_vec[0]->next = node_vec[k-1]->next;
            
          for(int i=0; i<k-1; i++){
              node_vec[k-1-i]->next = node_vec[k-2-i];
          }

        }
        
        return start.next;
    }
};