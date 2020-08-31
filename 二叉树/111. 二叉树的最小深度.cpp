/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        if (root->left && !root->right) {
            return minDepth(root->left) + 1;
        }

        if (root->right && !root->left) {
            return minDepth(root->right) + 1;
        }

        return min(minDepth(root->left)+1, minDepth(root->right)+1);
    }

    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        queue<pair<TreeNode *, int> > que;
        que.emplace(root, 1);
        while (!que.empty()) {
            auto node = que.front().first;
            int depth = que.front().second;
            que.pop();
            if (node->left == nullptr && node->right == nullptr) {
                return depth;
            }
            if (node->left != nullptr) {
                que.emplace(node->left, depth + 1);
            }
            if (node->right != nullptr) {
                que.emplace(node->right, depth + 1);
            }
        }
        return 0;
    }
};