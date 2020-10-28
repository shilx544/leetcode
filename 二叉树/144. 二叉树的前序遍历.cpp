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
    // 递归
    void helper(TreeNode* root, vector<int>& result) {
        if (!root) {
            return;
        }

        result.push_back(root->val);
        if (root->left) {
            helper(root->left, result);
        }
        if (root->right) {
            helper(root->right, result);
        }
        return;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;

        helper(root, result);
        return result;
    }

    // 迭代
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) {
            return result;
        }

        stack<TreeNode*> stk;
        stk.push(root);
        
        while (!stk.empty()) {
            auto node = stk.top();
            stk.pop();
            result.push_back(node->val);
            if (node->right) {
                stk.push(node->right);
            }
            
            if (node->left) {
                stk.push(node->left);
            }
        }
        return result;
    } 
};