class Solution {
private:
    void postOrderTra(TreeNode* root, vector<int>& result) {
        if (!root) {
           return;
        }

        if (root->left) {
           postOrderTra(root->left, result);
        }

        if (root->right) {
           postOrderTra(root->right, result);
        }

       result.push_back(root->val);
       return;
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postOrderTra(root, result);
        return result;
    }
};