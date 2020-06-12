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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        auto pre = head;
        auto next = head;
        auto current = head->next;
        while(current) {
            next = current->next;
            current->next = pre;
            pre = current;
            current = next;
        }
        head->next = nullptr;
        return pre;
    }

	ListNode* reverseList2(ListNode* head) {
		if (head == nullptr || head->next == nullptr) {
			return head;
		}

		auto p = reverseList2(head->next);
		head->next->next = head;
		head->next = nullptr;
		return p;
	}
};

