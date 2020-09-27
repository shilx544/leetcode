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
    int sumOfLeftLeaves(TreeNode* root) {
        int result = 0;

        if (!root) {
            return result;
        }

        if (root->left) {
            if (!root->left->left && !root->left->right) {
                result += root->left->val;
            }
            result += sumOfLeftLeaves(root->left);
        }

        if (root->right) {
            result += sumOfLeftLeaves(root->right);
        }

        return result;
    }
};