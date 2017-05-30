class Solution {
    bool found;
    int count = 0;
    TreeNode* dfs(TreeNode* root, int k) {
        if ( root == NULL ) return NULL;
        auto ret = dfs(root->left, k);
        if ( found ) return ret;
        if ( ++count == k ) { found = true; return root; }
        return dfs(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        found = false, count = 0;
        return dfs(root, k)->val;
    }
};
