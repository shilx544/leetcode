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
    ListNode* insertionSortList(ListNode* head) {
        while(!head || !head->next) {
            return head;
        }
        ListNode* dummy = new ListNode(0);
        // dummy->next = head;
        auto pre = dummy;
        auto cur = head;

        while (cur) {
            while(pre->next && cur->val > pre->next->val) {
                pre = pre->next;
            }
            auto next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            pre = dummy;
            cur = next;
        }
        return head;
    }
};