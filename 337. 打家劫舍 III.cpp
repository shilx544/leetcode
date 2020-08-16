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
    int rob(TreeNode* root) {
        if (!root ) {
            return 0;
        }

        int money = root->val;
        if (root->left) {
            money += (rob(root->left->left) + rob(root->left->right));
        }

        if (root->right) {
            money += (rob(root->right->left) + rob(root->right->right));
        }

        return max(money,rob(root->left) + rob(root->right));
    }

    int robInternal(TreeNode* root, unordered_map<TreeNode*, int> memo) {
        if (!root) {
            return 0;
        }
        unordered_map<TreeNode*, int>::iterator it = memo.begin();
        for (; it != memo.end(); ++it) {
            if (it->first == root) return memo[root];
        }

        int money = root->val;
        if (root->left) {
            money += (robInternal(root->left->left, memo) + robInternal(root->left->right, memo));
        }

        if (root->right) {
            money += (robInternal(root->right->left, memo) + robInternal(root->right->right, memo));
        }
        int result = max(money, robInternal(root->left, memo) + robInternal(root->right, memo));
        memo[root] = result;
        return money;
    }

    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> memo;
        return robInternal(root, memo);
    }
};