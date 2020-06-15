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
        if (!head->next) {
            return nullptr;
        }
        auto p = new ListNode(0);
        p->next = head;
        auto fast = p;
        auto slow = p;
        int cur = 0;
        while (fast->next) {
            if (cur < n) {
                fast = fast->next;
                cur++;
            } else {
                fast = fast->next;
                slow = slow->next;
            }
            //cout << fast->val << "," << slow->val << endl;
        }
        slow->next = slow->next->next;

        auto res = p->next;
        return res;
    }
};