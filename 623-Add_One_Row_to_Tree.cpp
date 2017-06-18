class Solution {
    TreeNode* helper(TreeNode* root, int v, int d, bool left) {
        if ( !d ) {
            TreeNode *node = new TreeNode(v);
            if ( left ) node->left = root;
            else node->right = root;
            return node;
        }
        if ( root == NULL ) return NULL;
        root->left  = helper(root->left, v, d-1, true);
        root->right = helper(root->right, v, d-1, false);
        return root;
    }
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        return helper(root, v, d-1, true);
    }
};
