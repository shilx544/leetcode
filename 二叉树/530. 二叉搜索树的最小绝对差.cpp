class Solution {
private:
    vector<int> vec;
public:
    void midOrder(TreeNode* root) {
        if (!root) {
            return;
        }
        midOrder(root->left);
        vec.push_back(root->val);
        midOrder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        vec.clear();
        midOrder(root);
        if (vec.size() < 2) {
            return 0;
        }
        int result = INT_MAX;
        for (int i = 1; i < vec.size(); ++i) {
            result = min(result, vec[i]-vec[i-1]);
        }

        return result;
    }
};