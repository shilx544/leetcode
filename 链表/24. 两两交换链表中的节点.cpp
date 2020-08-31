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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* pre = new ListNode(0);
        pre->next = head;
        auto p = head;
        head = p->next;
        while (p && p->next) {
            auto r = p;
            auto s = p->next;
            auto t = p->next->next;

            // 四个节点串联
            if (t && t->next) {
                r->next = s->next->next;
                s->next = r;
                p = t;
            } else {
                // 三个节点串联
                s->next = r;
                r->next = t;
                break;
            }
        }
        return head;
    }

    // 递归
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        auto p = head;
        auto q = head->next;
        p->next = swapPairs(q->next);
        q->next = p;
        return q;
    }
};