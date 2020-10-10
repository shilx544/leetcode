class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       auto fast = head;
       auto slow = head;
       while (fast && fast->next) {
           slow = slow->next;
           fast = fast->next->next;
           if (slow == fast) {
                auto index1 = fast;
                auto index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2; // 返回环的入口
            }
        }
        return nullptr;
    }
};