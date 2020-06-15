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

    void getLeafVal(TreeNode* root, vector<int>& result) {
        if (!root) return;

        if (!root->left && !root->right) {
            result.push_back(root->val);
        }
        getLeafVal(root->left, result);
        getLeafVal(root->right, result);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;
        getLeafVal(root1, v1);
        getLeafVal(root2, v2);
        return v1==v2;
    }
};