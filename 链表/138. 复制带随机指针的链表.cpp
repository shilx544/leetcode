/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head || !head->next) {
            return head;
        }
        unordered_map<Node*, Node*> randomNode;
        auto p = head;
        while(p) {
            Node* node = new Node(p->val);
            randomNode[p] = node;
            p = p->next;
        }
        p = head;
        while(p) {
            randomNode[p]->next = randomNode[p->next];
            randomNode[p]->random = randomNode[p->random];
            p = p->next;
        }
        return randomNode[head];
    }
};