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
private:
    void helper(TreeNode* root, vector<int>& result) {
        if (root->left) {
            helper(root->left, result);
        }

        if (root) {
            result.push_back(root->val);
        }

        if (root->right) {
            helper(root->right, result);
        }

        return;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;

        if (!root) {
            return result;
        }
        helper(root, result);
        return result;
    }

    // 迭代
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        vector<int> v;
        TreeNode* rt = root;
        while(rt || S.size()) {
            while(rt) {
                S.push(rt);
                rt=rt->left;
            }
            rt = S.top();
            S.pop();
            v.push_back(rt->val);
            rt = rt->right;
        }
        return v;        
    }
};