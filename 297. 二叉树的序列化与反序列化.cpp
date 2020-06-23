/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<string> split(string &data){
    int start = 0;
    vector<string> res;
    while(1){
        auto end = data.find(',',start);
        if(end == string::npos) break;
        res.push_back(data.substr(start,end-start));
        start = end+1;
    }
    return move(res);
}

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string res;
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            if(p!=NULL){
                res+=to_string(p->val);
                res+=',';
                q.push(p->left);
                q.push(p->right);
            }else res+="null,";
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty() || data.find('NULL') == 0) {
            return nullptr;
        }
        auto v = split(data);
        queue<TreeNode*> q;
        if (v[0] == "NULL") return nullptr;
        q.push(new TreeNode(stoi(v[0])));
        auto res = q.front();
        for (int i = 1; i < v.size();) {
            // 添加左节点
            if (v[i] != "NULL") {
                auto p = new TreeNode(stoi(v[i]));
                q.push(p);
                q.front()->left = p;
            }
            ++i;
            // 添加右节点
            if (v[i] != "NULL") {
                auto p = new TreeNode(stoi(v[i]));
                q.push(p);
                q.front()->right = p;
            }
            ++i;
            q.pop();
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));