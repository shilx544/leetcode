/*
思路：快慢指针后依次比较
*/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, * fast = head, * prev = nullptr;
        while (fast) {
            fast = fast->next ? fast->next->next : fast->next;
            slow = slow->next;
        }
        while (slow) {
            ListNode* tmp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }

        while(head && prev) {
            if (head->val != prev->val) {
                return false;
            }
            head = head->next;
            prev = prev->next;
        }
        return true;
    }
};