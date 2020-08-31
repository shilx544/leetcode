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
    ListNode* removeDuplicateNodes(ListNode* head) {
        set<int> s;
        auto p = new ListNode(0);
        p->next = head;
        auto q = head;
        while(q) {
            if (s.find(q->val) == s.end()) {
                s.insert(q->val);
                p = p->next;
                q = q->next;
                
            } else {
                p->next = q->next;
                q = q->next;
            }
        }
        return head;
    }
};