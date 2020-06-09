/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 我们可以考虑如果给的入参不是链表是数组的话，只需要求出前缀和，对于前缀和相同的项，那他们中间的部分即是可以消除掉的，比如以 [1, 2, 3, -3, 4] 为例，
// 其前缀和数组为 [1, 3, 6, 3, 7] ，我们发现有两项均为 3，则 6 和 第二个 3 所对应的原数组中的数字是可以消掉的。换成链表其实也是一样的思路，把第一个
// 3 的 next 指向第二个 3 的 next 即可

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        auto dummy = new ListNode(0);
        dummy->next = head;
        auto p = dummy;
        map<int, ListNode*> sum2Node;
        int pre = 0, sum = 0;
        sum2Node[0] = dummy;

        while(p = p->next) {
            pre += p->val;
            if (sum2Node.find(pre) == sum2Node.end()) {
                sum2Node[pre] = p;
            } else {
                auto tmp = sum2Node[pre]->next;
                sum = pre;
                // 删除中间段的节点
                sum2Node[sum]->next = p->next;
                while (tmp != p) {
                    sum+= tmp->val;
                    sum2Node.erase(sum);
                    tmp = tmp->next;
                }
            }
        }

        return dummy->next;
    }
};