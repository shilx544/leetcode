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
        if (!head) {
            return nullptr;
        }
        auto p = head;

        // 最后只剩一个元素
        if (! p->next) {
            return p;
        }

        // 最后只剩两个元素
        if (! p->next->next) {
            auto q = p->next;
            q->next = p;
            p->next = nullptr;
            return q;
        }
        
        swapPairs(p->next->next);
        return head;
    }
};