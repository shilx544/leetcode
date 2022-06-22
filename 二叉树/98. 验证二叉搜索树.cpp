class Solution {
public:
    long long maxVal = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        
        if (root == nullptr) {
            return true;
        }

        bool left = isValidBST(root->left);
        if (maxVal < root->val) {
            maxVal = root->val;
        } else {
            return false;
        }
        bool right = isValidBST(root->right);
        return left && right;
    }
};