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
    TreeNode *t1, *t2, *pre;
    void midOrder(TreeNode* root) {
        if (!root) return;
        midOrder(root->left);
        if (pre && pre->val > root->val) {
            if (!t1) t1 = pre;
            t2 = root;
        }
        pre = root;
        midOrder(root->right);
    }

    void recoverTree(TreeNode* root) {
        midOrder(root);
        swap(t1->val, t2->val);
    }
};