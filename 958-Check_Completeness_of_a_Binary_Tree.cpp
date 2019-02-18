class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if ( root == NULL ) return true;
        bool last = false;
        queue<TreeNode *> que;
        que.push(root);
        while ( !que.empty() ) {
            auto node = que.front();
            que.pop();
            if ( node->left == NULL ) last = true;
            if ( node->left != NULL ) {
                if ( last ) return false;
                que.push(node->left);
            }
            if ( node->right == NULL ) last = true;
            if ( node->right != NULL ) {
                if ( last ) return false;
                que.push(node->right);
            }
        }
        return true;
    }
};

static int __desyncio = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
