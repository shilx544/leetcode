struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void bfs(TreeNode* root){
    queue<Node *> nodeQueue;  
    nodeQueue.push(root);
    TreeNode *node;
    while(!nodeQueue.empty()){
        node = nodeQueue.front();
        nodeQueue.pop();
        cout << node->data << endl; //遍历根结点
        if(node->left){
            nodeQueue.push(node->left);  //先将左子树入队
        }
        if(node->right){
            nodeQueue.push(node->right);  //再将右子树入队
        }
    }