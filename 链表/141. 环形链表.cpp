class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) {
            return false;
        }
        auto p = head;
        auto q = head;
        while (p != NULL && p->next != NULL) {
            p = p->next->next;
            q = q->next;
            if (p == q) {
                return true;
            }
        }
        return false;
    }
};
