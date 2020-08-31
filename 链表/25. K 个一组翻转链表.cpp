/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 示例：
// 给你这个链表：1->2->3->4->5
// 当 k = 2 时，应当返回: 2->1->4->3->5
// 当 k = 3 时，应当返回: 3->2->1->4->5

class Solution {
public:
    ListNode* successor;
    ListNode* reverseN(ListNode* head, int n) {
        if (n == 1) {
            successor = head->next;
            return head;
        }

        auto last = reverseN(head->next, n-1);
        head->next->next = head;
        head->next = successor;
        return last;
    }

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == 1) {
            return reverseN(head, n);
        }

        head->next = reverseBetween(head->next, m-1, n-1);
        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = 0;
        auto p = head;
        while(p = p->next) {
            cnt++;
        }

        for (int i = 0; i < cnt/k; ++i) {
            head = reverseBetween(head, i*k + 1, i*k + k);
        }
        return head;
    }
};