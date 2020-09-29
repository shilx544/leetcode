class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        que.push(root);

        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            Node* node;
            Node* nodePre;
            for (int i = 0; i < size; ++i) {
                if (i == 0) {
                     nodePre = que.front(); // 取出一层的头结点
                    que.pop();
                    node = nodePre;
                } else {
                    node = que.front();
                    que.pop();
                    nodePre->next = node;
                    nodePre = node;
                }
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            nodePre->next = NULL; // 本层最后一个节点指向NULL
        }
        return root;
    }
};