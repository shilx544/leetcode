class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return NULL;
        }
        queue<Node*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            Node* node;
            Node* nodePre;
            for (int i = 0; i < size; ++i) {
                if (i == 0) {
                    nodePre = que.front(); // 记录一层的头结点
                    que.pop();
                    node = nodePre;
                } else {
                    node = que.front();
                    que.pop();
                    nodePre->next = node;
                    nodePre = nodePre->next;
                }

                if (node->left) {
                    que.push(node->left);
                }

                if (node->right) {
                    que.push(node->right);
                }
            }
            nodePre->next = NULL;
        }
        return root;
    }
private:
    void traversal(Node* cur) {
        if (cur == NULL) return;
                                // 中
        if (cur->left) cur->left->next = cur->right; // 操作1
        if (cur->right) {
            if (cur->next) cur->right->next = cur->next->left; // 操作2 
            else cur->right->next = NULL;
        }
        traversal(cur->left);   // 左
        traversal(cur->right);  // 右
    }
public:
    Node* connect2(Node* root) {
        traversal(root);
        return root;
    }
};