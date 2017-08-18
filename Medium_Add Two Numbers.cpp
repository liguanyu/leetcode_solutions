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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* l3 = new ListNode(0);
		ListNode* result = &(*l3);
		int temp = 0;
		while (l1 != nullptr || l2 != nullptr) {
			if (l1 == nullptr) {
				l1 = new ListNode(0);
			}
			if (l2 == nullptr) {
				l2 = new ListNode(0);
			}

			int s = l1->val + l2->val + temp;
			temp = 0;
			l1 = l1->next;
			l2 = l2->next;
			if (s >= 10) {
				s = s - 10;
				temp = 1;
			}
			l3->next = new ListNode(s);
			l3 = l3->next;
		}
		if (temp == 1) {
			l3->next = new ListNode(1);
		}
		return result->next;
    }
};
