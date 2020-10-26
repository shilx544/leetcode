class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return;
        }
        stack<ListNode*> stk;
        auto p = head;
        auto q = head->next;
        int n = 0;
        while (p) {
            n++;  // 节点个数
            p = p->next;
        }

        p = head;
        int n2 = n/2;
        while (n2--) {
            p = p->next;
        }

        auto mid = p;

        while (p) {
            stk.push(p);
            p = p->next;
        }

        p = head;
        while (!stk.empty()) {
            p->next = stk.top();
            stk.pop();
            p->next->next = q;
            p = q;
            q = p->next;
        }
        mid->next = NULL;
        return;
    }
};