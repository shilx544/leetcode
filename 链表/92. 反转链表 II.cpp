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
    ListNode* successor = nullptr;
    ListNode* reverseN(ListNode* head, int n) {

        if (n == 1) {
            successor = head->next;
            cout << successor->val << endl;
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
};