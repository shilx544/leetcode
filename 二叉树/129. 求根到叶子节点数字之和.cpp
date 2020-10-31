class Solution {
public:
    int helper(TreeNode* root, int sum) {
        if (!root) {
            return 0;
        }
        int result = sum * 10 + root->val;
        if (!root->left && !root->right) {
            return result;
        } else {
            return helper(root->left, result) + helper(root->right, result);
        }
    }

    int sumNumbers(TreeNode* root) {
        return helper(root,0);
    }
};