/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        } else if ((!p && q) || (p && !q) || (p->val != q->val)) {
            return false;
        }

        if (!p->left && !p->right && !q->left && !q->right && p->val == q->val) {
            return true;
        }

        bool bLeft = isSameTree(p->left, q->left);
        bool bRight = isSameTree(p->right, q->right);

        if (bLeft && bRight) {
            return true;
        }

        return false;
    }
};