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
    bool isSingleTree(TreeNode* root) {
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int result = 0;

        if (!root->left && !root->right) {
            return 0;
        }

        int left = diameterOfBinaryTree(root->left) + 1;
        int right = diameterOfBinaryTree(root->right) + 1;

        result = left + right > result ? left + right : result;
        return result;
    }
};