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
        return addTwoNumbers(l1, l2, 0);
    }

private:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry) {
        if (l1 == nullptr && l2 == nullptr && carry == 0) {
            return nullptr;
        }
        carry += (l1 == nullptr ? 0: l1->val) + (l2 == nullptr ? 0 : l2->val);
        auto ret = new ListNode(carry % 10);
        ret->next = addTwoNumbers(l1 == nullptr? nullptr:l1->next,
                                  l2 == nullptr? nullptr:l2->next,
                                  carry / 10);
        return ret;
    }
};